#ifndef QUIZDIALOG_HH
#define QUIZDIALOG_HH

#include "quizcategory.hh"
#include "quizentry.hh"
#include "quizplayer.hh"

#include <QDialog>
#include <QList>
#include <QString>
#include <QVector>

// Forward declarations.
class QuizButton;
class QCloseEvent;
class QLabel;

/**
 * Dialog for showing questions and counting points.
 */
class QuizDialog : public QDialog
{
    Q_OBJECT

  public:
    /**
     * Default Constructor.
     *
     * This creates the whole dialog window with all menus and elements.
     */
    QuizDialog( const QList<QuizCategory>& categories,
                const QList<QuizEntryPointers>& entries,
                const QList<QuizPlayer>& players );

  private slots:
    /**
     * Show the question under this coordinates.
     */
    void showQuestion(const int column, const int row, QuizEntry* entryP);

  protected:
    /**
     * Close dialog.
     */
    virtual void closeEvent(QCloseEvent *event);

  private:
    /**
     * Field with quiz buttons.
     */
    QVector<QVector<QuizButton*> > mButtons;

    /**
     * List for showing players points.
     */
    QVector<QLabel*> mPointsLabels;

    /**
     * Number of questions per category.
     */
    int mNumQuestions;

    /**
     * List of categories.
     */
    QList<QuizCategory> mCategories;

    /**
     * List of players.
     */
    QList<QuizPlayer> mPlayers;
};

#endif
