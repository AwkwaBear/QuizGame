#include "quizcategoryselection.hh"

QuizCategorySelection::QuizCategorySelection( QWidget* parent )
: QComboBox(parent)
{
    addItem(tr("Random"));
    setMinimumWidth(200);
}

// Set new categories for selection.
void QuizCategorySelection::setCategories( const QStringList& categories )
{
    clear();
    addItem(tr("Random"));
    addItems(categories);
}
