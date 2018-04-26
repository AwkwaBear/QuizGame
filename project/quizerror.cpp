#include "quizerror.hh"

QuizError::QuizError()
: state(QUIZ_ES_NOERROR), category("",-1), file(""), line("")
{
}
