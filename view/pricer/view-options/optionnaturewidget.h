#ifndef OPTIONNATUREWIDGET_H
#define OPTIONNATUREWIDGET_H

#include <QGroupBox>
#include <QRadioButton>

#include "options/OptionNature.h"


class OptionNatureWidget
    : public QGroupBox
{
    Q_OBJECT

private:
    static bool _callChecked;

public:
    explicit OptionNatureWidget(QWidget* parent = nullptr);

    OptionNature* optionNature() const;

protected:
    virtual void showEvent(QShowEvent* event);

private slots:
    void setCurrentNature(bool callChecked);

private:
    QRadioButton* _call;
    QRadioButton* _put;
};


#endif // OPTIONNATUREWIDGET_H
