#include <vector>
#include <bits/stdc++.h>

class Stats
{
public:
    float average;
    float max;
    float min;
};

class IAlerter
{
public:
    virtual void setAlert();
};

class EmailAlert : public IAlerter
{
public:
    void setAlert();
    bool emailSent;
};

class LEDAlert : public IAlerter
{
public:
    void setAlert();
    bool ledGlows;
};

class StatsAlerter
{
    float maxThreshold;
    std::vector<IAlerter*> alertVector;
public:
    StatsAlerter(const float, const std::vector<IAlerter*>&);
    void checkAndAlert(const std::vector<float>&);
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>&);
}
