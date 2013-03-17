/**
 * We shall say that an n-digit number is pandigital if it makes use of all the digits
 * 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5
 * pandigital.
 *
 * The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
 * multiplicand, multiplier, and product is 1 through 9 pandigital.
 *
 * Find the sum of all products whose multiplicand/multiplier/product identity can be
 * written as a 1 through 9 pandigital.
 *
 * HINT: Some products can be obtained in more than one way so be sure to only include
 * it once in your sum.
 *
 * @task 032
 * @answer 45228
 */
#include "../projecteuler.h"

bool isPandigital(UI number) {
    VI divisors = getAllDistinctDivisors(number);

    FOREACH(iter, divisors) {
        UI a = *iter, b = number / a;
        if (
            getDigitCount(number) + getDigitCount(a) + getDigitCount(b) == 9
            && (getDigitMask(a) | getDigitMask(b) | getDigitMask(number)) == 1022
        ) {
            if (false) {
                TRACE(a);
                TRACE(b);
                TRACE(number);
                cout << "-----------------" << endl;
            }
            return true;
        }
    }

    return false;
}

ULL solve032() {
    ULL sum = 0;

    FOR(i,1,100000) {
        if (isPandigital(i)) {
            //TRACE(i);
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << solve032();
    return 0;
}
