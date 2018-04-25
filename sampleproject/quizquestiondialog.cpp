#include "quizquestiondialog.hh"
#include "quizbutton.hh"
#include "quizplayerbutton.hh"

#include <QtGui>

// Default constructor.
QuizQuestionDialog::QuizQuestionDialog( const QuizCategory& category,
                                        const QuizEntry& entry,
                                        QList<QuizPlayer>& players,
                                        QWidget* parent )
: QDialog(parent)
{
    // layout for showing a question
    QVBoxLayout* questionLayoutP = new QVBoxLayout;

    QLabel* categoryLabelP = new QLabel;
    QLabel* subCategoryLabelP = new QLabel;

    if ( category.isRandom() )
    {
        // extract category from entryP
        categoryLabelP->setText( entry.categories().first() );
        subCategoryLabelP->setText( entry.subcategory());
    }
    else if ( category.isRandomSub() )
    {
        // extract subcategory from entryP
        categoryLabelP->setText( category.category() );
        subCategoryLabelP->setText( entry.subcategory() );
    }
    else
    {
        categoryLabelP->setText( category.category() );
        subCategoryLabelP->setText( category.subcategory() );
    }

    QFont font = categoryLabelP->font();
    font.setPointSize( 2*font.pointSize() );
    categoryLabelP->setFont(font);
    categoryLabelP->setAlignment( Qt::AlignCenter );
    questionLayoutP->addWidget( categoryLabelP );
    subCategoryLabelP->setFont(font);
    subCategoryLabelP->setAlignment( Qt::AlignCenter );
    questionLayoutP->addWidget( subCategoryLabelP );

    font.setPointSize( 2*font.pointSize() );

    QLabel* questionLabelP = new QLabel( entry.question() );
    questionLabelP->setFont(font);
    questionLabelP->setAlignment( Qt::AlignCenter );
    questionLabelP->setWordWrap(true);
    questionLayoutP->addWidget( questionLabelP );

    mAnswerLabelP = new QLabel( entry.answer() );
    mAnswerLabelP->setFont(font);
    mAnswerLabelP->setAlignment( Qt::AlignCenter );
    mAnswerLabelP->setWordWrap(true);

    QLabel* dummyLabelP = new QLabel;
    dummyLabelP->setMinimumSize( mAnswerLabelP->sizeHint() );

    QStackedWidget* stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(dummyLabelP);
    stackedWidget->addWidget(mAnswerLabelP);
    connect(this, SIGNAL(showWidget(int)),
            stackedWidget, SLOT(setCurrentIndex(int)));
    questionLayoutP->addWidget(stackedWidget);

    QHBoxLayout *buttonLayoutP = new QHBoxLayout;

    for ( int ii = 0; ii < players.size(); ii++ )
    {
        QuizPlayerButton* playerButtonP =
                           new QuizPlayerButton( players[ii], entry.points() );
        buttonLayoutP->addWidget(playerButtonP);
    }
    buttonLayoutP->addStretch();

    mShowButtonP = new QPushButton( tr("Show &answer") );
    mShowButtonP->setCheckable(true);
    connect(mShowButtonP, SIGNAL(toggled(bool)), this, SLOT(showAnswer(bool)));
    buttonLayoutP->addWidget( mShowButtonP );

    QPushButton* closeButtonP = new QPushButton( tr("&Close") );
    connect(closeButtonP, SIGNAL(clicked()), this, SLOT(close()));
    buttonLayoutP->addWidget( closeButtonP );

    questionLayoutP->addLayout(buttonLayoutP);

    setLayout(questionLayoutP);
    setWindowTitle( tr("Ubucon-Quiz 2013") );
    setMinimumSize(sizeHint());
}

// Show the answer to a question.
void QuizQuestionDialog::showAnswer(bool show)
{
    if ( show )
    {
        emit showWidget(1);
        mShowButtonP->setText(tr("Hide &answer"));
    }
    else
    {
        emit showWidget(0);
        mShowButtonP->setText(tr("Show &answer"));
    }
}
