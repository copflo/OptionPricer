#ifndef OptionFactory_h
#define OptionFactory_h

#include "AmericanOptionFactory.h"
#include "AssetOrNothingOptionFactory.h"
#include "CashOrNothingOptionFactory.h"
#include "ComboBoxStackedWidget.h"
#include "EuropeanOptionFactory.h"
#include "IAsianOptionFactory.h"
#include "IBarrierOptionFactory.h"
#include "LookbackOptionFactory.h"

class OptionFactory 
    : public QWidget
{
    Q_OBJECT

public:
    static const QString AMERICAN;
    static const QString ASSET_OR_NOTHING;
    static const QString CASH_OR_NOTHING;
    static const QString EUROPEAN;
    static const QString ASIAN;
    static const QString BARRIER;
    static const QString LOOKBACK;

public:
            OptionFactory (QWidget* parent = nullptr);
    virtual ~OptionFactory();

    QString getCurrentSelection() const;

    template<typename T>
    T* buildOption() const;

public slots:
    void changeCurrentOptionStyle(const QString& text);

signals:
    void currentOptionStyleChanged(const QString&);

private:
    AmericanOptionFactory* _american;
    AssetOrNothingOptionFactory* _assetOrNothing;
    CashOrNothingOptionFactory* _cashOrNothing;
    EuropeanOptionFactory* _european;
    IAsianOptionFactory* _asian;
    IBarrierOptionFactory* _barrier;
    LookbackOptionFactory* _lookback;
    ComboBoxStackedWidget* _content;
};

#endif /* OptionFactory_h */