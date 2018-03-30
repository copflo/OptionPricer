#include "KnockOut.h"


bool KnockOut::activated(bool barrierCrossed)
{
    return (barrierCrossed == false);
}

std::string KnockOut::toString()
{
    return "Out";
}

