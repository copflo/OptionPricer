#include "AssetOrNothingOptionFactory.h"

AssetOrNothingOptionFactory::AssetOrNothingOptionFactory(QWidget* parent)
    : PathIndependentOptionWidget(parent)
{
}

AssetOrNothingOptionFactory::~AssetOrNothingOptionFactory()
{
}

AssetOrNothingOption* AssetOrNothingOptionFactory::buildOption() const
{
    return new AssetOrNothingOption(optionNature(), maturity(), getStrike());
}