#ifndef ComboBoxStackedWidget_h
#define ComboBoxStackedWidget_h

#include <map>
#include <QComboBox>
#include <QStackedWidget>

class ComboBoxStackedWidget 
    : public QWidget
{
    Q_OBJECT

public:
            ComboBoxStackedWidget (std::initializer_list<std::pair<QString, QWidget*>>& list,
                                   QWidget* parent = nullptr);
            ComboBoxStackedWidget (const std::map<QString, QWidget*>& map, QWidget* parent = nullptr);
    virtual ~ComboBoxStackedWidget();

    QString getCurrentSelection()                           const;
    void    changeChoices      (const QStringList& choices);

public slots:
    void update(const QString& text);

signals:
    void currentSelectionChanged(const QString&);

private:
    void build();

protected:
    const std::map<QString, QWidget*> _map;
    QComboBox*        _combo;
    QStackedWidget*   _stack;
};

#endif /* ComboBoxStackedWidget_h */