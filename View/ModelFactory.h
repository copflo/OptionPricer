#ifndef ModelFactory_h
#define ModelFactory_h

#include "BlackScholesFactory.h"
#include "BlackScholesMonteCarloFactory.h"
#include "ComboBoxStackedWidget.h"
#include "CoxRossRubinsteinFactory.h"

class ModelFactory 
    : public QWidget
{
    Q_OBJECT

public:
    static const QString BLACK_SCHOLES;
    static const QString BLACK_SCHOLES_MC;
    static const QString COX_ROSS_RUBINSTEIN;
    static const std::map<QString, QStringList> _map;

public:
            ModelFactory(QWidget* parent = nullptr);
    virtual ~ModelFactory();

    QString getCurrentSelection() const;

    template<typename T> 
    T* buildModel() const;

public slots:
    void update(const QString& optionStyle);

private:
    BlackScholesFactory* _bs;
    CoxRossRubinsteinFactory* _crr;
    BlackScholesMonteCarloFactory* _bsMC;
    ComboBoxStackedWidget* _content;
};

#endif /* ModelFactory_h */