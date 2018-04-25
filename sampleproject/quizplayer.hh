#ifndef QUIZPLAYER_HH
#define QUIZPLAYER_HH

#include <QString>

/**
 * Quiz player with name and points.
 */
class QuizPlayer
{
  public:
    /**
     * Constructor.
     *
     * @param name Player name.
     */
    QuizPlayer( const QString& name );

    /**
     * @return name of player
     */
    const QString& getName() const;

    /**
     * @return points for answering correctly
     */
    int getPoints() const;

    /**
     * Adding (or subtracting) points.
     *
     * @param points Points, may be negative.
     */
    void addPoints( const int points );

  private:
    /**
     * Player name.
     */
    QString mName;

    /**
     * Points.
     */
    int mPoints;
};

// return name of player
inline
const QString& QuizPlayer::getName() const
{
    return mName;
}

// return points for answering correctly
inline
int QuizPlayer::getPoints() const
{
    return mPoints;
}

// Adding (or subtracting) points.
inline
void QuizPlayer::addPoints( const int points )
{
    mPoints += points;
}

#endif
