#include <math.h>

int isDecimalPointTwo(double num) {
    // Get the fractional part of the number
    double fractionalPart = num - (int)num;

    // Check if the fractional part is approximately equal to 0.2
    // Use a tolerance due to floating-point precision issues
    return fabs(fractionalPart - 0.2) < 1e-9;
}

// Function to check if a double has no decimal part
int hasNoDecimal(double num) {
    return fabs(num - (int)num) < 1e-9;
}