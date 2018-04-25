#include "quizerrormessagebox.hh"

#include "quizcategory.hh"
#include "quizerror.hh"

#include <QString>

// Show error box.
void QuizErrorMessageBox::show( QWidget * parent, const QuizError& error )
{
    QString title;
    QString text;

    switch ( error.state )
    {
        case QUIZ_ES_NOERROR:
            // This should not happen!
            title = tr("No error");
            text = tr("Why do you show this box then?");
            break;
        case QUIZ_ES_OUT_OF_QUESTIONS:
            title = tr("Error selecting entries");
            text = tr("Out of questions for\n");
            text += tr("category: ") + error.category.category() + "\n";
            text += tr("subcategory: ") + error.category.subcategory() + "\n";
            text += "\n";
            text += tr("Try selecting another category and/or subcategory.");
            break;
        case QUIZ_ES_REMOVE_ENTRY_NOT_POSSIBLE:
            title = tr("Error selecting entries");
            text += tr("Internal error: Removing quiz entry from list.");
            break;
        case QUIZ_ES_ADD_ENTRY_NOT_POSSIBLE:
            title = tr("Error reading file");
            text += tr("Internal error: Adding quiz entry to list.");
            break;
        case QUIZ_ES_EMPTY_FILENAME:
            title = tr("Error reading file");
            text = tr("Filename is empty.");
            break;
        case QUIZ_ES_COULD_NOT_OPEN_FILE:
            title = tr("Error reading file");
            text = tr("File could not be opened. Does it exists?");
            text += "\n\n" + tr("File: ") + error.file;
            break;
        case QUIZ_ES_READING_LINE_ERROR:
            title = tr("Error reading file");
            text = tr("Error reading line:\n");
            text += error.line + "\n";
            text += tr("from file ") + error.file;
            text += "\n\n";
            text += tr("Please check the file and try again.");
            break;
        default:
            // This should not happen!
            title = tr("Default case");
            text = tr("Do you have forgotten to implement some case?\n\n");
            text += tr("Case: ");
            text += error.state;
            break;
    }

    QMessageBox::critical( parent, title, text );
}
