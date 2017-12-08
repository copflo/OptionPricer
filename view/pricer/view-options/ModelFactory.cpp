#include <QVBoxLayout>

#include "ModelFactory.h"
#include "OptionFactory.h"


const QString ModelFactory::BLACK_SCHOLES = "Black Scholes";
const QString ModelFactory::BLACK_SCHOLES_MC = "Black Scholes - Monte Carlo";
const QString ModelFactory::BINOMIAL_TREE = "Binomial Tree";


ModelFactory::ModelFactory(QWidget* parent)
    : QWidget(parent)
    , _bs(new BlackScholesFactory)
    , _crr(new BinomialTreeFactory)
    , _bsMC(new BlackScholesMonteCarloFactory)
    , _comboBox(new QComboBox)
    , _stack(new QStackedWidget)
    , _modelMap{
        { OptionFactory::AMERICAN,         { BINOMIAL_TREE } },
        { OptionFactory::ASSET_OR_NOTHING, { BLACK_SCHOLES, BLACK_SCHOLES_MC } },
        { OptionFactory::CASH_OR_NOTHING,  { BLACK_SCHOLES, BLACK_SCHOLES_MC } },
        { OptionFactory::EUROPEAN,         { BLACK_SCHOLES, BLACK_SCHOLES_MC, BINOMIAL_TREE } },
        { OptionFactory::ASIAN,            { BLACK_SCHOLES_MC } },
        { OptionFactory::BARRIER,          { BLACK_SCHOLES_MC } },
        { OptionFactory::LOOKBACK,         { BLACK_SCHOLES_MC } }
      }
    , _widgetMap{
        { ModelFactory::BLACK_SCHOLES, _bs },
        { ModelFactory::BINOMIAL_TREE, _crr },
        { ModelFactory::BLACK_SCHOLES_MC, _bsMC }
      }
{
    QBoxLayout* layout = new QVBoxLayout(this);

    _stack->addWidget(_bs);
    _stack->addWidget(_crr);
    _stack->addWidget(_bsMC);

    layout->addWidget(_comboBox);
    layout->addWidget(_stack);

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SLOT(updateCurrentModel(const QString&)));

    connect(_comboBox, SIGNAL(currentTextChanged(const QString&)),
            this,      SIGNAL(currentModelChanged(const QString&)));
}

ModelFactory::~ModelFactory()
{
}

QString ModelFactory::currentModel() const
{
    return _comboBox->currentText();
}

template<>
BlackScholes* ModelFactory::buildModel<BlackScholes>() const
{
    return _bs->buildModel();
}

template<>
BinomialTree* ModelFactory::buildModel<BinomialTree>() const
{
    return _crr->buildModel();
}

template<>
BlackScholesMonteCarlo* ModelFactory::buildModel<BlackScholesMonteCarlo>() const
{
    return _bsMC->buildModel();
}

void ModelFactory::update(const QString& optionStyle)
{
    _comboBox->clear();
    _comboBox->addItems(_modelMap.at(optionStyle));
}

void ModelFactory::updateCurrentModel(const QString& modelName)
{
    auto pair = _widgetMap.find(modelName);
    if (pair != _widgetMap.end()) {
        _stack->setCurrentWidget(pair->second);
    }
}
