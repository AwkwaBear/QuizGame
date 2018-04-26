#ifndef QUIZQUESTIONDIALOG_HH
#define QUIZQUESTIONDIALOG_HH

#include "quizcategory.hh"
#include "quizentry.hh"
#include "quizplayer.hh"

#include <QDialog>

// Forward declarations.
class QLabel;
class QuizPlayer;

/**
 * Dialog for showing single question.
 */
class QuizQuestionDialog : public QDialog
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizQuestionDialog( const QuizCategory& category,
                        const QuizEntry& entry,
                        QList<QuizPlayer>& players,
                        QWidget* parent = 0 );

  signals:
    void showWidget(int);

  private slots:

    /**
     * Show the answer to a question.
     *
     * @param show If true, show the answer, else hide it.
     */
    void showAnswer(bool show);

  private:
    /**
     * Pointer to Label with answer that should be shown later.
     */
    QLabel* mAnswerLabelP;

    /**
     * Button for showing the answer or ending the round.
     */
    QPushButton* mShowButtonP;
};

#endif
