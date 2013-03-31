/**
 * It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 *
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 *
 * @task 052
 * @answer 142857
 */
#include "../projecteuler.h"

bool sameDigits(ULL x) {
    UI mask = getDigitMask(x);

    return (
           getDigitMask(2*x) == mask
        && getDigitMask(3*x) == mask
        && getDigitMask(4*x) == mask
        && getDigitMask(5*x) == mask
        && getDigitMask(6*x) == mask
    );
}

ULL solve052() {
    ULL x = 1, tenPower = 10;
    while (!sameDigits(x)) {
        x++;
        if (6 * x > tenPower) {
            x = tenPower;
            tenPower *= 10;
        }
    }

    return x;
}

int main() {
    cout << solve052();
    return 0;
}
