#include "quizdialog.hh"
#include "quizbutton.hh"
#include "quizquestiondialog.hh"

#include <QtGui>

// Default constructor.
QuizDialog::QuizDialog( const QList<QuizCategory>& categories,
                        const QList<QuizEntryPointers>& entries,
                        const QList<QuizPlayer>& players )
: mNumQuestions( QuizEntry::numQuestionsPerCategory ),
  mCategories( categories ),
  mPlayers( players )
{
    QGridLayout *questionLayoutP = new QGridLayout;
    mButtons.resize( categories.size() );
    for ( int ii = 0; ii < categories.size(); ii++ )
    {
        QLabel* categoryLabelP = new QLabel( categories[ii].category() );
        // change font to bigger size
        QFont font = categoryLabelP->font();
        font.setPointSize( 2*font.pointSize() );
        categoryLabelP->setFont(font);
        categoryLabelP->setAlignment( Qt::AlignCenter );
        categoryLabelP->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        questionLayoutP->addWidget( categoryLabelP, 0, ii );

        QLabel* subCategoryLabelP = new QLabel( categories[ii].subcategory() );
        subCategoryLabelP->setFont(font);
        subCategoryLabelP->setAlignment( Qt::AlignCenter );
        subCategoryLabelP->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        questionLayoutP->addWidget( subCategoryLabelP, 1, ii );

        mButtons[ii].resize(mNumQuestions);
        for ( int jj = 0; jj < mNumQuestions; jj++ )
        {
            QuizButton *buttonP = new QuizButton( ii, jj, entries[ii].entriesP[jj] );
            connect(buttonP, SIGNAL(clicked(const int,const int,QuizEntry*)), this, SLOT(showQuestion(const int,const int,QuizEntry*)));
            questionLayoutP->addWidget( buttonP, jj+2, ii );

            // store button in list
            mButtons[ii][jj] = buttonP;
        }
    }

    QHBoxLayout *playerLayoutP = new QHBoxLayout;
    mPointsLabels.resize( mPlayers.size() );
    for ( int ii = 0; ii < mPlayers.size(); ii++ )
    {
        QLabel* playerLabelP = new QLabel( mPlayers[ii].getName() + ": " );
        QFont font = playerLabelP->font();
        font.setPointSize( 2*font.pointSize() );
        playerLabelP->setFont(font);
        playerLabelP->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        playerLayoutP->addWidget(playerLabelP);

        mPointsLabels[ii] = new QLabel( QString("%1").arg( mPlayers[ii].getPoints() ) );
        mPointsLabels[ii]->setFont(font);
        mPointsLabels[ii]->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        playerLayoutP->addWidget(mPointsLabels[ii]);

        playerLayoutP->addStretch();
    }

    QPushButton* closeButtonP = new QPushButton( tr("&Close") );
    connect(closeButtonP, SIGNAL(clicked()), this, SLOT(close()));
    playerLayoutP->addWidget( closeButtonP );

    QVBoxLayout* dialogLayoutP = new QVBoxLayout;
    dialogLayoutP->addLayout(questionLayoutP);
    dialogLayoutP->addLayout(playerLayoutP);

    setLayout(dialogLayoutP);

    setWindowTitle( tr("Ubucon-Quiz 2013") );
}

// Show the question under this coordinates.
void QuizDialog::showQuestion(const int column, const int row, QuizEntry* entryP)
{
    QuizQuestionDialog dialog( mCategories[column], *entryP, mPlayers );
    dialog.exec();

    // Update points of all players
    for ( int ii = 0; ii < mPlayers.size(); ii++ )
    {
        mPointsLabels[ii]->setText( QString("%1").arg( mPlayers[ii].getPoints() ) );
    }

    // disable button so that it cannot be clicked again
    mButtons[column][row]->setEnabled(false);

    // mark entry as used
    entryP->setUsed();
}

// Close dialog.
void QuizDialog::closeEvent(QCloseEvent *event)
{
    if ( mPlayers.size() > 0 )
    {
        // Checking which player has won!
        int winnerIndex = 0;
        QStringList winners;

        for ( int ii = 0; ii < mPlayers.size(); ii++ )
        {
            if ( mPlayers[ii].getPoints() > mPlayers[winnerIndex].getPoints() )
            {
                winnerIndex = ii;
                winners.clear();
                winners.append( mPlayers[ii].getName() );
            }
            else if ( mPlayers[ii].getPoints() == mPlayers[winnerIndex].getPoints() )
            {
                winners.append( mPlayers[ii].getName() );
            }
        }

        QString text;

        if ( winners.size() == 1 )
        {
            text += winners[0] + tr(" has won the game.");
            text += tr("\n\nCongratulation!");
        }
        else
        {
            text += tr("There are several winners:\n\n");
            text += winners.join(", ");
            text += tr("\n\nCongratulation!");
        }

        QMessageBox::information( this, tr("And the winner is ..."), text );

    }
    // else we do not have enough players and shouldn't have started
    // the quiz at all!

    event->accept();
}
