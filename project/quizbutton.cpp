#include "quizbutton.hh"
#include "quizentry.hh"

QuizButton::QuizButton( const int column, const int row, QuizEntry* entryP, QWidget* parent )
: QPushButton(parent), mColumn(column), mRow(row), mEntryP(entryP)
{
    // Groessere Schrift einstellen
    QFont aFont = font();
    aFont.setPointSize( 3*aFont.pointSize() );
    setFont( aFont );

    setText( QString("%1").arg(mEntryP->points()) );
    setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    connect(this, SIGNAL(clicked()), this, SLOT(setClickedSignal()));
}

void QuizButton::setClickedSignal()
{
    emit clicked(mColumn,mRow,mEntryP);
}
