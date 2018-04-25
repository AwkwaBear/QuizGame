#ifndef QUIZCATEGORYSELECTION_HH
#define QUIZCATEGORYSELECTION_HH

#include <QComboBox>

// Forward declarations
class QStringList;
class QWidget;

/**
 * Some special box for selecting a new category.
 */
class QuizCategorySelection : public QComboBox
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizCategorySelection( QWidget* parent = 0 );

    /**
     * Set new categories for selection.
     *
     * @param categories List of categories.
     */
    void setCategories( const QStringList& categories );
};

#endif
