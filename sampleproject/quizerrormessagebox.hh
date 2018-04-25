#ifndef QUIZERRORMESSAGEBOX_HH
#define QUIZERRORMESSAGEBOX_HH

#include <QMessageBox>

// Forward declarations.
class QWidget;
class QString;
class QuizError;

/**
 * Box showing error message.
 */
class QuizErrorMessageBox : public QMessageBox
{
    Q_OBJECT

  public:
    /**
     * @param parent The parent widget of this message box
     * @param error The error state that adds additional text.
     */
    static void show( QWidget * parent, const QuizError& error );
};

#endif
