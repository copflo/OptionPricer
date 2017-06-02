#include <QVBoxLayout>
#include "ModelFactory.h"
#include "OptionFactory.h"
#include <QDebug>

const QString ModelFactory::BLACK_SCHOLES = "Black Scholes";
const QString ModelFactory::BLACK_SCHOLES_MC = "Black Scholes - Monte Carlo";
const QString ModelFactory::COX_ROSS_RUBINSTEIN = "Cox Ross Rubinstein";

const std::map<QString, QStringList> ModelFactory::_map = {
    { OptionFactory::AMERICAN,         { ModelFactory::COX_ROSS_RUBINSTEIN } },
    { OptionFactory::ASSET_OR_NOTHING, { ModelFactory::BLACK_SCHOLES, ModelFactory::BLACK_SCHOLES_MC } },
    { OptionFactory::CASH_OR_NOTHING,  { ModelFactory::BLACK_SCHOLES, ModelFactory::BLACK_SCHOLES_MC } },
    { OptionFactory::EUROPEAN,         { ModelFactory::BLACK_SCHOLES, ModelFactory::BLACK_SCHOLES_MC,  ModelFactory::COX_ROSS_RUBINSTEIN } },
    { OptionFactory::ASIAN,            { ModelFactory::BLACK_SCHOLES_MC } },
    { OptionFactory::BARRIER,          { ModelFactory::BLACK_SCHOLES_MC } },
    { OptionFactory::LOOKBACK,         { ModelFactory::BLACK_SCHOLES_MC } }
};

ModelFactory::ModelFactory(QWidget* parent)
    : QWidget(parent)
    , _bs(new BlackScholesFactory)
    , _crr(new CoxRossRubinsteinFactory)
    , _bsMC(new BlackScholesMonteCarloFactory)
    , _content(new ComboBoxStackedWidget {
                    {
                        { ModelFactory::BLACK_SCHOLES, _bs },
                        { ModelFactory::COX_ROSS_RUBINSTEIN, _crr },
                        { ModelFactory::BLACK_SCHOLES_MC, _bsMC }
                    } 
               })
{
    QBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_content);
}

ModelFactory::~ModelFactory()
{
}

QString ModelFactory::getCurrentSelection() const
{
    return _content->getCurrentSelection();
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
    _content->changeChoices(_map.at(optionStyle));
}
