#include <cmath>

using namespace std;
double s_calculation(double x, double y, double z) {
    return pow(x, 2) - pow(y, 3) + sqrt(abs(pow(z, 2) * exp(x))) / sqrt(12 * x + (pow(y, 2) - M_PI * sqrt(z)));
}
