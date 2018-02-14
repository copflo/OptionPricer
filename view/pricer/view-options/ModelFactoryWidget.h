#ifndef ModelFactoryWidget_h
#define ModelFactoryWidget_h

#include <QComboBox>
#include <QStackedWidget>

#include "BlackScholesWidget.h"
#include "BlackScholesMonteCarloWidget.h"
#include "BinomialTreeWidget.h"


class ModelFactoryWidget
    : public QWidget
{
    Q_OBJECT

public:
            ModelFactoryWidget (QWidget* parent = nullptr);
    virtual ~ModelFactoryWidget();

    void setAvailableModels(const std::vector<std::string>& models);
    std::string choice() const;

    const BinomialTreeWidget& binomialTreeUI() const;
    const BlackScholesWidget& blackScholesUI() const;
    const BlackScholesMonteCarloWidget& blackScholesMcUI() const;

signals:
    void currentModelChanged(const QString&);

private slots:
    void updateCurrentModel(const QString& modelName);

private:
    QComboBox*      _comboBox;
    QStackedWidget* _stack;
    BinomialTreeWidget* _bitree;
    BlackScholesWidget* _bs;
    BlackScholesMonteCarloWidget* _bsMC;
    std::map<std::string, QWidget*> _widgetMap;
};


#endif // ModelFactoryWidget_h
