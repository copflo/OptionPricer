#ifndef UNDERLYINGWIDGET_H
#define UNDERLYINGWIDGET_H

#include <QLineEdit>


class UnderlyingWidget 
    : public QWidget
{
    Q_OBJECT

public:
    explicit UnderlyingWidget(QWidget* parent = nullptr);
    ~UnderlyingWidget();

private:
    QLineEdit* _marketPlace;
    QLineEdit* _underlying;
    QLineEdit* _isin;
    QLineEdit* _name;
};


#endif // UNDERLYINGWIDGET_H
