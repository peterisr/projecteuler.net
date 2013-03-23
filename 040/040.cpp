/**
 * An irrational decimal fraction is created by concatenating the positive integers:
 *
 * 0.123456789101112131415161718192021...
 *
 * It can be seen that the 12th digit of the fractional part is 1.
 *
 * If dn represents the nth digit of the fractional part, find the value of the following expression.
 *
 * d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000
 *
 * @task 040
 * @answer 210
 */
#include "../projecteuler.h"

UI solve040() {
    UI result = 1, i = 1, nextNumber = 2, lookFor = 10;
    while (lookFor <= 1e6) {
        UI length = getDigitCount(nextNumber);
        if (i + length >= lookFor) {
            VUI digits = getDigits(nextNumber, 10);
            F(j,length) {
                if (i + j + 1 == lookFor) {
                    result *= digits[j];
                    TRACE(digits[j]);
                    lookFor *= 10;
                    break;
                }
            }
        }

        i += length;
        nextNumber++;
    }

    return result;
}

int main() {
    cout << solve040();
    return 0;
}
