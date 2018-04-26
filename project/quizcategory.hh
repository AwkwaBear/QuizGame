#ifndef QUIZCATEGORY_HH
#define QUIZCATEGORY_HH

#include <QObject>
#include <QString>

/**
 * Class for storing category.
 */
class QuizCategory
{
  public:
    /**
     * Constructor.
     */
    QuizCategory( const QString& cat, const int id );

    /**
     * Comparison operator.
     *
     * Random categories are "bigger" than specific categories.
     */
    bool operator<( const QuizCategory& other ) const;

    /**
     * @return category
     */
    const QString& category() const;


    /**
     * @return index
     */
     int index() const;

    /**
     * @return true if the category is random.
     */
    bool isRandom() const;


  private:
    /**
     * Category
     */
    QString mCategory;


    /**
     * Index in the list.
     *
     * This is the index of the category in the original selection.
     * We need to store it so that we can sort a list with QuizCategory
     * and remember the right order.
     */
    int mIndex;
};


// return category
inline
const QString& QuizCategory::category() const
{
    return mCategory;
}

// return index
inline
int QuizCategory::index() const
{
    return mIndex;
}

// return true if the category is random.
inline
bool QuizCategory::isRandom() const
{
    return ( mCategory == QObject::tr("Random") );
}

#endif
