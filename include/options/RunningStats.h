#ifndef RunningSimulation_h
#define RunningSimulation_h

#include <chrono>


typedef std::chrono::duration<double> seconds;

class RunningStats
{
public:
    RunningStats ();
    ~RunningStats();

    void    update           (double value);
	
    double  mean             () const;
    double  variance         () const;
    double  stdDeviation     () const;
    size_t  nbObservations   () const;
    seconds timeOfComputation() const;

private:
    size_t _nbIter;
    double _mean;
    double _squareSumOfDiff;
    std::chrono::time_point<std::chrono::system_clock, seconds> _begin;
};


#endif // RunningSimulation_h
