#ifndef AssetOrNothingOptionFactory_h
#define AssetOrNothingOptionFactory_h

#include "../Options/AssetOrNothingOption.h"
#include "pathindependentoptionwidget.h"

class AssetOrNothingOptionFactory 
    : public PathIndependentOptionWidget
{
public:
            AssetOrNothingOptionFactory (QWidget* parent = nullptr);
    virtual ~AssetOrNothingOptionFactory();

    AssetOrNothingOption* buildOption() const;
};

#endif //AssetOrNothingOptionFactory_h