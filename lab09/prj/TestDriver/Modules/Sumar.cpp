#include <iostream>
#include <cmath>
#include "Sumar.h"

using namespace std;

double s_calculation(double x, double y, double z) {
    // Check the denominator to avoid sqrt of negative number or division by zero
    double denominator = 12 * x + (pow(y, 2) - M_PI * sqrt(abs(z)));
    if (denominator <= 0) {
        cout << "Помилка: знаменник у виразі sqrt(12 * x + (y^2 - π * sqrt(z))) від'ємний або дорівнює нулю.\n";
        return 0.0; // Return 0 as an error indicator
    }

    // Calculate the expression
    double numerator = sqrt(abs(pow(z, 2) * exp(x)));
    double denominatorSqrt = sqrt(denominator);
    if (denominatorSqrt == 0) { // Additional check to avoid division by zero
        cout << "Помилка: ділення на нуль у виразі.\n";
        return 0.0;
    }

    return pow(x, 2) - pow(y, 3) + numerator / denominatorSqrt;
}
