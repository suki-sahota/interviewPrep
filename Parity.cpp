/**
 * Author: Suki Sahota
 */
#include <cstdint>

class Parity {
public:
    /**
     * Finds parity of given integer
     * and returns 1 if odd parity 
     * and returns 0 if even parity.
     * Time complexity is logarithmic!
     */
    uint32_t findParity(uint32_t val) {
        uint32_t num_bits = 16;
        uint32_t mask = 0xFFF;

        uint32_t left_half = val >> num_bits;
        uint32_t right_half = val & mask;

        while (left_half > 1 || right_half > 1) {
            num_bits >>= 1;
            mask >>= num_bits; // using updated num_bits

            uint32_t result = left_half ^ right_half;

            left_half = result >> num_bits;
            right_half = result & mask;
        }

        return left_half ^ right_half;
    }
};
