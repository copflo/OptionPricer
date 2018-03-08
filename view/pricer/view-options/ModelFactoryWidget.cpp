#include <QVBoxLayout>

#include "controller_options/Labels.h"

#include "ModelFactoryWidget.h"


ModelFactoryWidget::ModelFactoryWidget(QWidget* parent)
    : QWidget(parent)
    , _comboBox(new QComboBox)
    , _stack(new QStackedWidget)
    , _bitree(new BinomialTreeWidget)
    , _bs(new BlackScholesWidget)
    , _bsMC(new BlackScholesMonteCarloWidget)
    , _widgetMap{
        { Labels<QString>::Models::BINOMIAL_TREE, _bitree },
        { Labels<QString>::Models::BLACK_SCHOLES, _bs },
        { Labels<QString>::Models::BLACK_SCHOLES_MC, _bsMC }
      }
{
    _stack->addWidget(_bs);
    _stack->addWidget(_bitree);
    _stack->addWidget(_bsMC);

    QBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_comboBox);
    layout->addWidget(_stack);

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SLOT(updateCurrentModel(const QString&)));

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SIGNAL(currentModelChanged(const QString&)));
}

ModelFactoryWidget::~ModelFactoryWidget()
{
}

void ModelFactoryWidget::setAvailableModels(const std::vector<QString>& models)
{
    _comboBox->clear();
    for(auto& model : models) {
        _comboBox->addItem(model);
    }
}

QString ModelFactoryWidget::choice() const
{
    return _comboBox->currentText();
}

const BinomialTreeWidget& ModelFactoryWidget::binomialTreeUI() const
{
    return *_bitree;
}

const BlackScholesWidget& ModelFactoryWidget::blackScholesUI() const
{
    return *_bs;
}

const BlackScholesMonteCarloWidget& ModelFactoryWidget::blackScholesMcUI() const
{
    return *_bsMC;
}

void ModelFactoryWidget::updateCurrentModel(const QString& modelName)
{
    auto pair = _widgetMap.find(modelName);
    if (pair != _widgetMap.end()) {
        _stack->setCurrentWidget(pair->second);
    }
}
