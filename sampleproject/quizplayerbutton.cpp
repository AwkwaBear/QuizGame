#include "quizplayerbutton.hh"

// Constructor.
QuizPlayerButton::QuizPlayerButton( QuizPlayer& player,
                                    const int points,
                                    QWidget* parent )
: QPushButton(parent), mPlayer(player), mPoints(points)
{
    setText( QString("%1: +%2").arg(mPlayer.getName()).arg(mPoints) );
    setCheckable(true);
    connect( this, SIGNAL(toggled(bool)), this, SLOT(addPoints(bool)) );
}

// Add or subtract points for player.
void QuizPlayerButton::addPoints( bool add )
{
    if ( add )
    {
        mPlayer.addPoints( mPoints );
        setText( QString("%1: -%2").arg(mPlayer.getName()).arg(mPoints) );
    }
    else
    {
        mPlayer.addPoints( -mPoints );
        setText( QString("%1: +%2").arg(mPlayer.getName()).arg(mPoints) );
    }
}
