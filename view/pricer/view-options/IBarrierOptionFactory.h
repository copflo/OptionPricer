#ifndef IBarrierOptionFactory_h
#define IBarrierOptionFactory_h

#include <functional>
#include <map>

#include "options/BarrierOption.h"

#include "strikewidget.h"
#include "pathdependentoptionwidget.h"


class IBarrierOptionFactory 
    : public PathDependentOptionWidget
{
private:
    enum Direction {
        UP,
        DOWN
    };

    enum Knock {
        IN,
        OUT
    };

public:
            IBarrierOptionFactory (QWidget* parent = nullptr);
    virtual ~IBarrierOptionFactory();

    IBarrierOption* buildOption() const;

private:
    Direction getDirection ()                                                               const;
    Knock     getKnock     ()                                                               const;
    QWidget*  buildGroupBox(const QString& title, QRadioButton* first, QRadioButton* second);

    template<typename T> IBarrierOption* buildOptionStyle() const;

private:
    QRadioButton* _up;
    QRadioButton* _down;

    QRadioButton* _in;
    QRadioButton* _out;

    StrikeWidget*   _strike;
    QDoubleSpinBox* _barrier;                                                                 

private:
    const std::map<std::pair<Direction, Knock>, std::function<IBarrierOption*()>> _build {
        { { UP, IN },    std::bind(&IBarrierOptionFactory::buildOptionStyle<UpInBarrierOption>, this) },
        { { DOWN, IN },  std::bind(&IBarrierOptionFactory::buildOptionStyle<DownInBarrierOption>, this) },
        { { UP, OUT },   std::bind(&IBarrierOptionFactory::buildOptionStyle<UpOutBarrierOption>, this) },
        { { DOWN, OUT }, std::bind(&IBarrierOptionFactory::buildOptionStyle<DownOutBarrierOption>, this) }
    };
};


template<typename T>
IBarrierOption* IBarrierOptionFactory::buildOptionStyle() const
{
    return new T(optionNature(), maturity(), observationFrequency(), _strike->strike(), _barrier->value());
}


#endif // IBarrierOptionFactory_h
