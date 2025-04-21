#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

struct DepositResult {
    double monthlyInterest;
    double totalInterest;
    bool valid;
};

DepositResult depositCalculation(double depositAmount, int termMonths);

int getBeaufortScale(double windSpeed);

struct WindSpeedResult {
    double maxWindSpeed;
    int maxBeaufort;
    int maxWindSpeedDay;
    bool valid;
};

WindSpeedResult windSpeedBeaufort(double windSpeeds[31], const std::string beaufortDescriptions[13]);

struct BinaryCountResult {
    int result;
    bool isD13Set;
    bool valid;
};

BinaryCountResult binaryCount(long long number);

double calculation(double x, double y, double z);

#endif 