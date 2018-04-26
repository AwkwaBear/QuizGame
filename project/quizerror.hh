#ifndef QUIZERROR_HH
#define QUIZERROR_HH

#include "quizcategory.hh"

/**
 * Enumerator with different error types.
 */
enum QuizErrorState
{
    QUIZ_ES_NOERROR,                    // no error
    QUIZ_ES_OUT_OF_QUESTIONS,           // no questions for this category available
    QUIZ_ES_ADD_ENTRY_NOT_POSSIBLE,     // quiz entry could not be added
    QUIZ_ES_REMOVE_ENTRY_NOT_POSSIBLE,  // quiz entry could not be removed
    QUIZ_ES_EMPTY_FILENAME,             // file name is empty
    QUIZ_ES_COULD_NOT_OPEN_FILE,        // file could not be opened
    QUIZ_ES_READING_LINE_ERROR          // reading a line from file
};

/**
 * Error while using the quiz.
 *
 * The class is used for storing error states if there were errors
 * opening files or reading them or selecting the questions etc.
 */
class QuizError
{
  public:
    /**
     * Default Constructor.
     */
    QuizError();

    /**
     * @return TRUE if everything is okay.
     */
    bool noError() const;

   public:
     /**
      * Type of error that occured.
      */
     QuizErrorState state;

     /**
      * Optional category that produced and error.
      */
     QuizCategory category;

     /**
      * Optional file that has an error.
      */
     QString file;

     /**
      * Optional line while reading file.
      */
     QString line;
};

// return TRUE if everything is okay.
inline
bool QuizError::noError() const
{
    return ( QUIZ_ES_NOERROR == state );
}

#endif
