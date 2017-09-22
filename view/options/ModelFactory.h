#ifndef ModelFactory_h
#define ModelFactory_h

#include <QComboBox>
#include <QStackedWidget>

#include "BlackScholesFactory.h"
#include "BlackScholesMonteCarloFactory.h"
#include "CoxRossRubinsteinFactory.h"


class ModelFactory 
    : public QWidget
{
    Q_OBJECT

public:
    static const QString BLACK_SCHOLES;
    static const QString BLACK_SCHOLES_MC;
    static const QString COX_ROSS_RUBINSTEIN;

public:
            ModelFactory (QWidget* parent = nullptr);
    virtual ~ModelFactory();

    QString currentModel() const;

    template<typename T> T* buildModel() const;

public slots:
    void update(const QString& optionStyle);

private slots:
    void updateCurrentModel(const QString& modelName);

signals:
    void currentModelChanged(const QString&);

private:
    BlackScholesFactory*           _bs;
    CoxRossRubinsteinFactory*      _crr;
    BlackScholesMonteCarloFactory* _bsMC;
    QComboBox*                     _comboBox;
    QStackedWidget*                 _stack;

    const std::map<QString, QStringList> _modelMap;
    const std::map<QString, QWidget*> _widgetMap;
};


#endif // ModelFactory_h
