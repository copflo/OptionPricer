#include "KnockOut.h"

KnockOut::KnockOut()
{
}

KnockOut::~KnockOut()
{
}

bool KnockOut::activated(bool barrierCrossed) const
{
    return (barrierCrossed == false);
}

std::string KnockOut::toString() const
{
    return "Out";
}

