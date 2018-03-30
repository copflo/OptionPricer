#include "KnockIn.h"


bool KnockIn::activated(bool barrierCrossed)
{
    return barrierCrossed;
}

std::string KnockIn::toString()
{
    return "In";
}
