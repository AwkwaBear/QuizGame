#include "quizsubcategoryselection.hh"

QuizSubCategorySelection::QuizSubCategorySelection(
                              const QMap<QString, QStringList>& subCategoryMap,
                              QWidget* parent )
: QComboBox(parent), mSubCategoryMap(subCategoryMap)
{
    setMinimumWidth(200);
    setEnabled(false);
}

// Set new categories for selection.
void QuizSubCategorySelection::setCategories( const QStringList& categories )
{
    if ( categories.isEmpty() )
    {
        clear();
        setEnabled(false);
    }
    else
    {
        clear();
        addItem(tr("Random"));
        addItems(categories);
        setEnabled(true);
    }
}

// Sets a new category and shows the correct list of subcategories.
void QuizSubCategorySelection::setNewCategory( const QString& category )
{
    setCategories(mSubCategoryMap[category]);
}
