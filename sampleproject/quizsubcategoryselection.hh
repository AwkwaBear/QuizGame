#ifndef QUIZSUBCATEGORYSELECTION_HH
#define QUIZSUBCATEGORYSELECTION_HH

#include <QComboBox>

// Forward declarations
class QStringList;
class QWidget;

/**
 * Some special box for selecting a new subcategory.
 */
class QuizSubCategorySelection : public QComboBox
{
    Q_OBJECT

  public:
    /**
     * Constructor.
     */
    QuizSubCategorySelection( const QMap<QString, QStringList>& subCategoryMap,
                              QWidget* parent = 0 );

  public slots:
    /**
     * Sets a new category and shows the correct list of subcategories.
     *
     * @param category New main category.
     */
    void setNewCategory( const QString& category );

  private:
    /**
     * Set new subcategories for selection.
     *
     * @param categories List of subcategories.
     */
    void setCategories( const QStringList& categories );

  private:
    /**
     * Mapping of categories to subcategories
     */
    const QMap<QString, QStringList>& mSubCategoryMap;
};

#endif
