#include "KnockIn.h"

KnockIn::KnockIn()
{
}

KnockIn::~KnockIn()
{
}

bool KnockIn::activated(bool barrierCrossed) const
{
    return barrierCrossed;
}

std::string KnockIn::toString() const
{
    return "In";
}
