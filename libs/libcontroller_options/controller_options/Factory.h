#ifndef FACTORY_H
#define FACTORY_H


template<class ToBuild>
class Factory
{
public:
    template<class UI>
    static ToBuild* build(const UI& ui);
};


#endif // FACTORY_H