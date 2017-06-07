#include <stdexcept>
#include "AccuracyConfidence.h"
#include "math_functions.h"

AccuracyConfidence::AccuracyConfidence(double accuracy, double confidence)
    : _ratio(inverse_std_normal_cdf((confidence + 1.) / 2.) / accuracy)
{
    if (accuracy <= 0.0) {
        throw std::runtime_error("Accuracy cannot be negative or null");
    }

    if ((0.0 >= confidence) || (confidence >= 1.0)) {
        throw std::runtime_error("Confidence level must be between 0 or 1 (excluded)");
    }
}

AccuracyConfidence::~AccuracyConfidence()
{
}

bool AccuracyConfidence::stop(const RunningStats& stats) const
{
    return (sqrt(stats.nbObservations()) / stats.stdDeviation()) >= _ratio;
}
