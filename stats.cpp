#include "stats.h"

void IAlerter::setAlert()
{}

void EmailAlert::setAlert()
{
    this->emailSent = true;
}

void LEDAlert::setAlert()
{
    this->ledGlows = true;
}

StatsAlerter::StatsAlerter(const float maxThreshold, const std::vector<IAlerter*>& alert_vector)
    : maxThreshold(maxThreshold),
      alertVector(alert_vector)
{}

void StatsAlerter::checkAndAlert(const std::vector<float>& data) {
    if (*(std::min_element(data.begin(), data.end())) > this->maxThreshold) {
        for (auto itr : this->alertVector) {
            itr->setAlert();
        }
    }
}

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    Stats data_stats;
    if (data.empty()) {
        data_stats.average = NAN;
        data_stats.max = NAN;
        data_stats.min = NAN;
    } else {
        data_stats.average = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
        data_stats.min = *(std::min_element(data.begin(), data.end()));
        data_stats.max = *(std::max_element(data.begin(), data.end()));
    }
    return data_stats;
}
