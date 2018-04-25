#ifndef QUIZBUTTON_HH
#define QUIZBUTTON_HH

#include "quizentry.hh"

#include <QPushButton>

// Forward declarations
class QuizEntry;

/**
 * Some special button for associating a question with it.
 */
class QuizButton : public QPushButton
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizButton( const int column, const int row,
                QuizEntry* entryP, QWidget* parent = 0 );

  signals:
    void clicked(const int, const int, QuizEntry*);

  private slots:
    /**
     * Set signal with id of button.
     */
    void setClickedSignal();

  private:
    /**
     * Column number of button location
     */
    int mColumn;

    /**
     * Row number of button location.
     */
    int mRow;

    /**
     * Pointer to the quiz entry.
     */
    QuizEntry* mEntryP;
};

#endif
