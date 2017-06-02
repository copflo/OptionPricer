#include <algorithm>
#include <QVBoxLayout>
#include "ComboBoxStackedWidget.h"

ComboBoxStackedWidget::ComboBoxStackedWidget(std::initializer_list<std::pair<QString, QWidget*>>& list,
                                             QWidget* parent)
    : QWidget(parent)
    , _map(list.begin(), list.end())
    , _combo(new QComboBox)
    , _stack(new QStackedWidget)
{
    build();
}

ComboBoxStackedWidget::ComboBoxStackedWidget(const std::map<QString, QWidget*>& map, QWidget* parent)
    : QWidget(parent)
    , _map(map)
    , _stack(new QStackedWidget)
    , _combo(new QComboBox)
{
    build();
}

ComboBoxStackedWidget::~ComboBoxStackedWidget()
{
}

QString ComboBoxStackedWidget::getCurrentSelection() const
{
    return _combo->currentText();
}

void ComboBoxStackedWidget::changeChoices(const QStringList& choices)
{
    _combo->clear();
    _combo->addItems(choices);
}

void ComboBoxStackedWidget::update(const QString& text)
{
    if (_map.count(text) > 0) {
        _stack->setCurrentWidget(_map.at(text));
        emit currentSelectionChanged(text);
    }
}

void ComboBoxStackedWidget::build()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    
    for (const auto& pair : _map) {
        _combo->addItem(pair.first);
        _stack->addWidget(pair.second);
    }

    layout->addWidget(_combo);
    layout->addWidget(_stack);

    connect(_combo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(update(const QString&)));
}