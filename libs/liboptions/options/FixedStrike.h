#ifndef FixedStrike_h
#define FixedStrike_h


class FixedStrike
{
public:
            FixedStrike(double strike);
    virtual ~FixedStrike();

    double strike() const;

protected:
    double _strike;
};


#endif // FixedStrike_h
