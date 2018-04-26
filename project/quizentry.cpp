#include "quizentry.hh"

#include <iostream>

// This constructor sets all necessary values.
QuizEntry::QuizEntry( const QStringList& categories,
                      const QString& question,
                      const QString& answer,
                      const int points )
  : mCategories(categories),
    mQuestion(question), mAnswer(answer),
    mPoints(points), mUsed(false), mSelected(false), mValid(false)
{
    // There must be at least one category.
    if ( mCategories.isEmpty() )
    {
        return;
    }

    // No category is allowed to be empty.
    for ( int ii = 0; ii < mCategories.size(); ii++ )
    {
        if ( mCategories[ii].isEmpty() )
        {
             return;
        }
    }

    // The question must not be empty.
    if ( mQuestion.isEmpty() )
    {
        return;
    }

    // The answer must not be empty.
    if ( mAnswer.isEmpty() )
    {
        return;
    }

    // The points must be one of 100,200,300 or 400.
    if ( 100 != mPoints && 200 != mPoints && 300 != mPoints && 400 != mPoints)
    {
        return;
    }

    // Everything seems to be okay
    mValid = true;
}

// Default constructor.
QuizEntryPointers::QuizEntryPointers()
{
    for ( int ii = 0; ii < QuizEntry::numQuestionsPerCategory; ii++ )
    {
        entriesP[ii] = 0;
    }
}
