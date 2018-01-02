#ifndef OPTIONALSTRIKEWIDGET_H
#define OPTIONALSTRIKEWIDGET_H

#include <QCheckBox>

#include "strikewidget.h"


class OptionalStrikeWidget
    : public StrikeWidget
{
public:
    OptionalStrikeWidget(QWidget* parent = nullptr);

    bool isFloating() const;
    virtual double strike() const;

private:
    QCheckBox* _floating;
};


#endif // OPTIONALSTRIKEWIDGET_H
