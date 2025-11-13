
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function: computes x^n using recursion
    double solve(double x, long n) {
        // Base Case: anything raised to 0 is 1
        if (n == 0)
            return 1;

        // If exponent is negative, invert x and make n positive
        if (n < 0)
            return 1 / solve(x, -n);

        // If n is even → x^n = (x*x)^(n/2)
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        }

        // If n is odd → x^n = x * (x*x)^((n-1)/2)
        return x * solve(x * x, (n - 1) / 2);
    }

    // Main function that calls the helper
    double myPow(double x, int n) {
        // Convert n to long to handle edge case when n = INT_MIN
        // because -INT_MIN overflows the int range
        return solve(x, (long)n);
    }
};
