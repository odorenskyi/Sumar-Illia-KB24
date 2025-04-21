#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

using namespace std; // Додано, але не рекомендується

// Structure to hold deposit calculation results
struct DepositResult {
    double monthlyInterest;
    double totalInterest;
    bool valid;
};

// Task 9.1: Deposit calculation
DepositResult depositCalculation(double depositAmount, int termMonths);

// Task 9.2: Beaufort scale helper
int getBeaufortScale(double windSpeed);

// Structure to hold wind speed Beaufort results
struct WindSpeedResult {
    double maxWindSpeed;
    int maxBeaufort;
    int maxWindSpeedDay;
    bool valid;
};

// Task 9.2: Wind speed in Beaufort scale
WindSpeedResult windSpeedBeaufort(double windSpeeds[31], const string beaufortDescriptions[13]);

// Structure to hold binary count results
struct BinaryCountResult {
    int result;
    bool isD13Set;
    bool valid;
};

// Task 9.3: Binary count
BinaryCountResult binaryCount(long long number);

// Task 9.4: Calculation (wrapper for s_calculation)
double calculation(double x, double y, double z);

#endif // FUNCTIONS_H
