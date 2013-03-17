/**
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are
 * equal to the sum of the factorial of their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 *
 * @task 034
 * @answer 40730
 */
#include "../projecteuler.h"

UI isCurious(UI number) {
    static UI factorials[10], gen = 0;

    if (!gen) {
        factorials[0] = 1;
        FOR(i,1,10) {
            factorials[i] = factorials[i - 1] * i;
        }

        gen = 1;
    }

    UI digitFactorSum = 0, iter = number;
    while (iter) {
        digitFactorSum += factorials[iter % 10];
        iter /= 10;
    }

    return (digitFactorSum == number);
}

ULL solve034() {
    ULL sum = 0;

    FOR(i,10,3 * 1000 * 1000) {
        if (isCurious(i)) {
            TRACE(i);
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << solve034();
    return 0;
}
