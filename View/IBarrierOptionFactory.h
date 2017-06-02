#ifndef IBarrierOptionFactory_h
#define IBarrierOptionFactory_h

#include <functional>
#include <map>
#include "../Options/BarrierOption.h"
#include "pathdependentoptionwidget.h"

class IBarrierOptionFactory 
    : public PathDependentOptionWidget
{
public:
            IBarrierOptionFactory (QWidget* parent = nullptr);
    virtual ~IBarrierOptionFactory();

    IBarrierOption* buildOption() const;

private:
    std::string getDirection ()                                                                const;
    std::string getKnock     ()                                                                const;
    QWidget*    buildGroupBox(const QString& title, QRadioButton* first, QRadioButton* second);

    template<typename T>
    IBarrierOption* buildOptionStyle() const;

private:
    QRadioButton* _up;
    QRadioButton* _down;

    QRadioButton* _in;
    QRadioButton* _out;

    QDoubleSpinBox* _strike;
    QDoubleSpinBox* _barrier;                                                                 

private:
    typedef std::pair<std::string, std::string> key;
    typedef std::function<IBarrierOption*()> value;
    const std::map<key, value> _build {
        { { "up", "in" },    std::bind(&IBarrierOptionFactory::buildOptionStyle<UpInBarrierOption>, this) },
        { { "down", "in" },  std::bind(&IBarrierOptionFactory::buildOptionStyle<DownInBarrierOption>, this) },
        { { "up", "out" },   std::bind(&IBarrierOptionFactory::buildOptionStyle<UpOutBarrierOption>, this) },
        { { "down", "out" }, std::bind(&IBarrierOptionFactory::buildOptionStyle<DownOutBarrierOption>, this) }
    };
};

template<typename T>
IBarrierOption* IBarrierOptionFactory::buildOptionStyle() const
{
    return new T(optionNature(),
                 maturity(),
                 observationFrequency(),
                 _strike->value(),
                 _barrier->value());
}

#endif /* IBarrierOptionFactory_h */