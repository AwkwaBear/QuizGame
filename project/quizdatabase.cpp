#include "quizdatabase.hh"

#include <iostream>

#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QTime>

// Loads the questions from csv file and store it in the database.
QuizError QuizDatabase::load( const QString& fileName )
{
    QuizError error;

    if ( !fileName.isEmpty() )
    {
        QList<QuizEntry> newEntries;

        // open the file and read line by line
        QFile file(fileName);
        if ( file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            QTextStream input(&file);

            while (!input.atEnd())
            {
                QString line = input.readLine();

                // process the read lines
                if ( !readCsvLine(newEntries,line) )
                {
                    error.state = QUIZ_ES_READING_LINE_ERROR;
                    error.file = fileName;
                    error.line = line;
                    break;
                }
            }
            file.close();

            if ( error.noError() )
            {
                // Everything seems fine, so we can copy the entries
                if ( !setData(newEntries) )
                {
                    error.state = QUIZ_ES_ADD_ENTRY_NOT_POSSIBLE;
                }
            }
        }
        else
        {
            error.state = QUIZ_ES_COULD_NOT_OPEN_FILE;
            error.file = fileName;
        }
    }
    else
    {
        error.state = QUIZ_ES_EMPTY_FILENAME;
    }

    return error;
}

// Reads a single semicolon separated line.
bool QuizDatabase::readCsvLine( QList<QuizEntry>& entries, const QString& line )
{
    bool retValue = false;

    // we should have following fields:
    // Category;Question;Answer;Points
    QStringList splitLine = line.split(";");
    if ( 4 == splitLine.size() )
    {
        // We will create a new record
        QuizEntry entry ( splitLine[0].split(","),
                          splitLine[1],
                          splitLine[2],
                          splitLine[3].toInt() );

        if ( entry.isValid() )
        {
            entries.append(entry);
            retValue = true;
        }
    }

    return retValue;
}

// Set new database and create some meta information.
bool QuizDatabase::setData( const QList<QuizEntry>& entries )
{
    // We will not check if the data is valid. This must have been done before!
    bool retVal = true;

    mQuizEntries = entries;

    mCategories.clear();

    for ( int jj = 0; jj < QuizEntry::numQuestionsPerCategory; jj++ )
    {
        mCategoryEntryMap[jj].clear();
        mEntryMap[jj].clear();
    }

    for ( int ii = 0; ii < mQuizEntries.size(); ii++ )
    {
        const QStringList& tmpCategories = mQuizEntries[ii].categories();

        for ( int jj = 0; jj < tmpCategories.size(); jj++ )
        {
            QString category = tmpCategories[jj];

            // Add category
            if ( !mCategories.contains(category) )
            {
                // The category was not added before.
                mCategories.append(category);
                mCategories.sort();
            }
        }

        if ( !addEntryPtr( &mQuizEntries[ii] ) )
        {
            retVal = false;
            break;
        }
    }

    return retVal;
}

// Return the array index for a point value.
int QuizDatabase::getPointIndex( const int points ) const
{
    int index = -1;

    switch ( points )
    {
        case 100:
          index = 0;
          break;
        case 200:
          index = 1;
          break;
        case 300:
          index = 2;
          break;
        case 400:
          index = 3;
          break;
        default:
          break;
    }
    return index;
}

// add some entry pointer to the lists
bool QuizDatabase::addEntryPtr( QuizEntry* entryP )
{
    bool retVal = false;

    if ( entryP )
    {
        retVal = true;

        const QStringList& tmpCategories = entryP->categories();
        const int index = getPointIndex( entryP->points() );

        for ( int jj = 0; jj < tmpCategories.size(); jj++ )
        {
            QString category = tmpCategories[jj];

            if ( !mCategoryEntryMap[index][category].contains(entryP) )
            {
                mCategoryEntryMap[index][category].append(entryP);
            }
            else
            {
                // Entry already exists in one if the lists.
                // This should not happen!
                std::cerr << "(EE) QuizDatabase::addEntryPtr "
                          << std::hex << entryP << std::dec
                          << " Pointer already stored in"
                          << " " << mCategoryEntryMap[index][category].contains(entryP)
                          << std::endl;
                retVal = false;
                break;
            }
        }

        if ( retVal )
        {
            if ( !mEntryMap[index].contains(entryP) )
            {
                mEntryMap[index].append(entryP);
            }
            else
            {
                // Entry already exists in one if the lists.
                // This should not happen!
                std::cerr << "(EE) QuizDatabase::addEntryPtr "
                          << entryP
                          << " Pointer already stored in"
                          << " " << mEntryMap[index].contains(entryP)
                          << std::endl;
                retVal = false;
            }
        }
    }

    return retVal;
}

// remove some entry pointer from all lists
bool QuizDatabase::removeEntryPtr( QuizEntry* entryP )
{
    bool retVal = false;

    if ( entryP )
    {
        retVal = true;

        const QStringList& tmpCategories = entryP->categories();
        const int index = getPointIndex( entryP->points() );

        for ( int jj = 0; jj < tmpCategories.size(); jj++ )
        {
            QString category = tmpCategories[jj];

            if ( mCategoryEntryMap[index][category].contains(entryP))
            {
                mCategoryEntryMap[index][category].removeOne(entryP);
            }
            else
            {
                // The entry could not be removed from one list
                // That should not happen!
                std::cerr << "(EE) QuizDatabase::removeEntryPtr "
                          << "0x" << std::hex << entryP << std::dec
                          << " Pointer not found in "
                          << " " << mCategoryEntryMap[index][category].contains(entryP)
                          << std::endl;

                retVal = false;
                break;
            }
        }

        if ( retVal )
        {
            if ( mEntryMap[index].contains(entryP) )
            {
                mEntryMap[index].removeOne(entryP);
            }
            else
            {
                // The entry could not be removed from one list
                // That should not happen!
                std::cerr << "(EE) QuizDatabase::removeEntryPtr "
                          << "0x" << std::hex << entryP << std::dec
                          << " Pointer not found in "
                          << " " << mEntryMap[index].contains(entryP)
                          << std::endl;

                retVal = false;
            }
        }
    }

    return retVal;
}

// Try to select the entries for the quiz.
QuizError QuizDatabase::selectEntries( const QList<QuizCategory>& categories,
                                       QList<QuizEntryPointers>& entries )
{
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    // First we must sort the categories in the right order. That means that
    // we first must select the questions for specific categories like
    // "Movies -> Star Wars", then the category randoms like "Movies -> Random"
    // and then the random ones like "Random".
    // Otherwise it would be possible that we select a random question and
    // for the next specific category we would not have enough questions left.
    QList<QuizCategory> tmpCategories = categories;
    qSort( tmpCategories.begin(), tmpCategories.end() );

    /*
    for ( int ii = 0; ii < tmpCategories.size(); ii++ )
    {
        std::cout << "Kategorie " << tmpCategories[ii].index()
                  << ": "  << tmpCategories[ii].category().toStdString()
                  << " Order: " << ii
                  << std::endl;
    }
    */

    // Now iterate over all categories and get the right questions.
    QList<QuizEntryPointers> tmpEntries;
    QuizError error;

    for ( int ii = 0; ii < tmpCategories.size(); ii++ )
    {
        QuizEntryPointers entryPointers;

        error = getQuizEntryPointers( entryPointers, tmpCategories[ii] );

        if ( error.noError() )
        {
            tmpEntries.append( entryPointers );
        }
        else
        {
            break;
        }
    }

    if ( !error.noError() )
    {
        // we need to to a rollback and insert the selected questions
        // into the database again.
        for ( int ii = 0; ii < tmpEntries.size(); ii++ )
        {
            for ( int jj = 0; jj < QuizEntry::numQuestionsPerCategory; jj++ )
            {
                if ( tmpEntries[ii].entriesP[jj] )
                {
                    addEntryPtr( tmpEntries[ii].entriesP[jj] );
                }
            }
        }
    }
    else
    {
        // sort questions in right order
        for ( int ii = 0; ii < tmpCategories.size(); ii++ )
        {
            for ( int jj = 0; jj < tmpCategories.size(); jj++ )
            {
                if ( ii == tmpCategories[jj].index() )
                {
                    entries.append( tmpEntries[jj] );
                    break;
                }
            }
        }
    }

    return error;
}

// Add unused entries from the list.
bool QuizDatabase::addUnusedEntries( QList<QuizEntryPointers>& entries )
{
    bool retVal = true;

    for ( int ii = 0; ii < entries.size(); ii++ )
    {
        for ( int jj = 0; jj < QuizEntry::numQuestionsPerCategory; jj++ )
        {
            if ( entries[ii].entriesP[jj] &&
                 !entries[ii].entriesP[jj]->isUsed() )
            {
                if ( !addEntryPtr( entries[ii].entriesP[jj] ) )
                {
                    retVal = false;
                    break;
                }
            }
        }
    }

    return retVal;
}

// Get question block for quiz.
QuizError QuizDatabase::getQuizEntryPointers( QuizEntryPointers& entryPointers,
                                              const QuizCategory& category )
{
    QuizError error;

    if ( category.isRandom() )
    {
        error = getQuizEntryPointers(entryPointers);
    }
    else
    {
        error = getQuizEntryPointers( entryPointers,
                                      category);
    }

    if ( !error.noError() )
    {
        error.category = category;
    }

    return error;
}

// Get question block for quiz.
QuizError QuizDatabase::getQuizEntryPointers( QuizEntryPointers& entryPointers )
{
    QuizError error;

    if ( isOneQuestionBlockLeft() )
    {
        for ( int ii = 0; ii < QuizEntry::numQuestionsPerCategory; ii++ )
        {
            const int max = mEntryMap[ii].size();
            if ( max > 0 )
            {
                const int index = qrand() % max;
                entryPointers.entriesP[ii] = mEntryMap[ii][index];
                if ( !removeEntryPtr( entryPointers.entriesP[ii] ) )
                {
                    error.state = QUIZ_ES_REMOVE_ENTRY_NOT_POSSIBLE;
                    break;
                }
            }
            else
            {
                error.state = QUIZ_ES_OUT_OF_QUESTIONS;
                break;
            }
        }
    }
    else
    {
        error.state = QUIZ_ES_OUT_OF_QUESTIONS;
    }

    return error;
}


// Check if there is at least one question block left
bool QuizDatabase::isOneQuestionBlockLeft() const
{
    bool retVal = true;

    for ( int ii = 0; ii < QuizEntry::numQuestionsPerCategory; ii++ )
    {
        /*
        std::cout << "Search Random: " << ii
                  << " Size: " << mEntryMap[ii].size()
                  << std::endl;
        */

        if ( mEntryMap[ii].size() == 0 )
        {
            // one list is empty so we do not hve enough questions left
            retVal = false;
            break;
        }
    }

    return retVal;
}

// Check if there is at least one question block left
bool QuizDatabase::isOneQuestionBlockLeft( const QString& category ) const
{
    bool retVal = true;

    for ( int ii = 0; ii < QuizEntry::numQuestionsPerCategory; ii++ )
    {
        /*
        std::cout << "Search Random " << category.toStdString()
                  << ": " << ii
                  << " Size: " << mCategoryEntryMap[ii][category].size()
                  << std::endl;
        */

        if ( mCategoryEntryMap[ii][category].size() == 0 )
        {
            // one list is empty so we do not have enough questions left
            retVal = false;
            break;
        }
    }

    return retVal;
}
