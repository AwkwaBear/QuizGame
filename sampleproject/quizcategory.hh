#ifndef QUIZCATEGORY_HH
#define QUIZCATEGORY_HH

#include <QObject>
#include <QString>

/**
 * Class for storing category and subcategory.
 */
class QuizCategory
{
  public:
    /**
     * Constructor.
     */
    QuizCategory( const QString& cat, const QString& sub, const int id );

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
     * @return category
     */
    const QString& subcategory() const;

    /**
     * @return index
     */
     int index() const;

    /**
     * @return true if the category is random.
     */
    bool isRandom() const;

    /**
     * @return true if the subcategory is random.
     */
    bool isRandomSub() const;

  private:
    /**
     * Category
     */
    QString mCategory;

    /**
     * Subcategory
     */
    QString mSubcategory;

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

// return category
inline
const QString& QuizCategory::subcategory() const
{
    return mSubcategory;
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

// Return true if the subcategory is random.
inline
bool QuizCategory::isRandomSub() const
{
    return ( mSubcategory == QObject::tr("Random") );
}

#endif
