/**
 * Author: Suki Sahota
 */
#include <stdlib.h>

using namespace std;

class Pow {
public:
    /**
     * Calculates x raised to the power
     * of n (as such x^n).
     */
    double myPow(double x, int n) {
        // Base case: x^0
        if (n == 0) { return 1; }
        
        long N = labs(n);
        double base = x;
        double factor = 1;
        
        while (N > 1) {
            if (N & 1) {
                factor = factor * base;
                --N;
            } else {
                base = base * base;
                N = N >> 1;
            }
        }
        
        base = base * factor;
        
        return n > 0 ? base : 1 / base;
    }
};
