#ifndef QUIZWINDOW_HH
#define QUIZWINDOW_HH

#include "quizdatabase.hh"

#include <QMainWindow>

// Forward declarations
class QuizCategorySelection;

class QLineEdit;
class QPushButton;

/**
 * Main window for the quiz.
 *
 * If you want to start a new quiz you should create this window
 * and call show() to it.
 */
class QuizWindow : public QMainWindow
{
    Q_OBJECT

  public:
    /**
     * Default Constructor.
     *
     * This creates the whole application window with all menus and elements.
     */
    QuizWindow();

  private slots:
    /**
     * Load questions.
     *
     * This shows a file dialog where you can load a csv file with the
     * questions.
     */
    void loadQuestions();

    /**
     * Start quiz.
     *
     * The quiz is started with the selected categories and player.
     */
    void startQuiz();

  private:
    /**
     * Init window elements.
     */
    void init();

    /**
     * Add a new category and subcategory.
     */
    void addNewCategoryBox();

    /**
     * select new color for some player
     */
    void selectNewPlayerColor( const int index );

  private:

    /**
     * Maximum number of categories.
     */
    static const int mMaxNumberCategories = 4;

    /**
     * List for combo boxes for possible categories.
     */
    QuizCategorySelection* mCategorySelectionP[mMaxNumberCategories];


    static const int mMaxNumberPlayers = 4;

    /**
     * Line for edit of player names.
     */
    QLineEdit* mPlayerLineP[mMaxNumberPlayers];

    /**
     * Button for loading the questions.
     */
    QPushButton* mLoadButtonP;

    /**
     * Button for starting the game.
     */
    QPushButton* mStartButtonP;

    /**
     * Database with all loaded questions.
     */
    QuizDatabase mDataBase;
};

#endif
