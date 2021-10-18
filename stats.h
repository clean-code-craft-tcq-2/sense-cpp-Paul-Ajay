#include <vector>
#include <bits/stdc++.h>

class Stats
{
public:
    float average;
    float max;
    float min;
};

class IAlerter {};

class EmailAlert : public IAlerter
{
public:
    bool emailSent;
};
class LEDAlert : public IAlerter
{
public:
    bool ledGlows;
};
class StatsAlerter
{
public:
    StatsAlerter(const float, const std::vector<IAlerter*>&);
    void checkAndAlert(const std::vector<float>&);
};


namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&);
}
