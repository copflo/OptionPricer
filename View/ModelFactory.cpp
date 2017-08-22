#include <QVBoxLayout>

#include "ModelFactory.h"
#include "OptionFactory.h"


const QString ModelFactory::BLACK_SCHOLES = "Black Scholes";
const QString ModelFactory::BLACK_SCHOLES_MC = "Black Scholes - Monte Carlo";
const QString ModelFactory::COX_ROSS_RUBINSTEIN = "Cox Ross Rubinstein";


const std::map<QString, QStringList> ModelFactory::_modelMap = {
    { OptionFactory::AMERICAN,         { COX_ROSS_RUBINSTEIN } },
    { OptionFactory::ASSET_OR_NOTHING, { BLACK_SCHOLES, BLACK_SCHOLES_MC } },
    { OptionFactory::CASH_OR_NOTHING,  { BLACK_SCHOLES, BLACK_SCHOLES_MC } },
    { OptionFactory::EUROPEAN,         { BLACK_SCHOLES, BLACK_SCHOLES_MC, COX_ROSS_RUBINSTEIN } },
    { OptionFactory::ASIAN,            { BLACK_SCHOLES_MC } },
    { OptionFactory::BARRIER,          { BLACK_SCHOLES_MC } },
    { OptionFactory::LOOKBACK,         { BLACK_SCHOLES_MC } }
};

ModelFactory::ModelFactory(QWidget* parent)
    : QWidget(parent)
    , _bs(new BlackScholesFactory)
    , _crr(new CoxRossRubinsteinFactory)
    , _bsMC(new BlackScholesMonteCarloFactory)
    , _comboBox(new QComboBox)
    , _stack(new QStackedWidget)
    , _widgetMap{
        { ModelFactory::BLACK_SCHOLES, _bs },
        { ModelFactory::COX_ROSS_RUBINSTEIN, _crr },
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
CoxRossRubinstein* ModelFactory::buildModel<CoxRossRubinstein>() const
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
