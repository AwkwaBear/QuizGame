#ifndef QUIZPLAYERBUTTON_HH
#define QUIZPLAYERBUTTON_HH

#include "quizplayer.hh"

#include <QPushButton>

/**
 * Special button for adding/subtracting points to some player.
 */
class QuizPlayerButton : public QPushButton
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizPlayerButton( QuizPlayer& player,
                      const int points,
                      QWidget* parent = 0 );

  private slots:
    /**
     * Add or subtract points for player.
     *
     * @param add If true than add points, else subtract it.
     */
    void addPoints( bool add );

  private:
    /**
     * Player
     */
    QuizPlayer& mPlayer;

   /**
    * Points that could be earned.
    */
   const int mPoints;
};

#endif
