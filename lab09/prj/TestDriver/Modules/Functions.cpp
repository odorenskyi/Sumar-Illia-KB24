#include <iostream>
#include <iomanip>
#include <cmath>
#include "Functions.h"
#include "Sumar.h"

using namespace std;

// Task 9.1: Deposit calculation
DepositResult depositCalculation(double depositAmount, int termMonths) {
    DepositResult result;
    result.valid = false;

    if (termMonths <= 0 || depositAmount <= 0) {
        return result;
    }

    double annualRate = (termMonths <= 6) ? 16.0 : 18.0;
    double monthlyRate = annualRate / 12.0 / 100.0;
    result.monthlyInterest = depositAmount * monthlyRate;
    result.totalInterest = result.monthlyInterest * termMonths;
    result.valid = true;

    return result;
}

// Task 9.2: Beaufort scale helper
int getBeaufortScale(double windSpeed) {
    if (windSpeed < 0.3) return 0;
    else if (windSpeed <= 1.5) return 1;
    else if (windSpeed <= 3.3) return 2;
    else if (windSpeed <= 5.4) return 3;
    else if (windSpeed <= 7.9) return 4;
    else if (windSpeed <= 10.7) return 5;
    else if (windSpeed <= 13.8) return 6;
    else if (windSpeed <= 17.1) return 7;
    else if (windSpeed <= 20.7) return 8;
    else if (windSpeed <= 24.4) return 9;
    else if (windSpeed <= 28.4) return 10;
    else if (windSpeed <= 32.6) return 11;
    else return 12;
}

// Task 9.2: Wind speed in Beaufort scale
WindSpeedResult windSpeedBeaufort(double windSpeeds[31], const string beaufortDescriptions[13]) {
    WindSpeedResult result;
    result.valid = true;

    result.maxWindSpeed = windSpeeds[0];
    result.maxBeaufort = getBeaufortScale(windSpeeds[0]);
    result.maxWindSpeedDay = 1;

    for (int day = 0; day < 31; day++) {
        int beaufort = getBeaufortScale(windSpeeds[day]);
        if (windSpeeds[day] > result.maxWindSpeed) {
            result.maxWindSpeed = windSpeeds[day];
            result.maxBeaufort = beaufort;
            result.maxWindSpeedDay = day + 1;
        }
    }

    return result;
}

// Task 9.3: Binary count
BinaryCountResult binaryCount(long long number) {
    BinaryCountResult result;
    result.valid = false;

    if (number < 0 || number > 9008000) {
        return result;
    }

    result.isD13Set = (number & (1LL << 13)) != 0;

    int zeros = 0, ones = 0;
    for (int i = 0; i < 32; i++) {
        if (number & (1LL << i)) {
            ones++;
        } else {
            zeros++;
        }
    }

    result.result = result.isD13Set ? ones : zeros;
    result.valid = true;

    return result;
}

// Task 9.4: Calculation (wrapper for s_calculation)
double calculation(double x, double y, double z) {
    return s_calculation(x, y, z);
}
