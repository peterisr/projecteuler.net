/**
 * A googol (10^100) is a massive number: one followed by one-hundred zeros; 100^100 is almost unimaginably large:
 * one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
 *
 * Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
 *
 * @task 056
 * @answer 972
 */
#include "../projecteuler.h"

UI getDigitSum(mpz_class a) {
    mpz_class sum = 0;

    while (a > 0) {
        sum += (a % 10);
        a /= 10;
    }

    return sum.get_ui();
}

mpz_class linearPow(UI a, UI b) {
    mpz_class result = 1, aa = a;
    FOR(i,0,b) {
        result *= aa;
    }

    return result;
}

UI solve056() {
    UI maxSum = 0;

    FOR(a,1,101) {
        FOR(b,1,101) {
            mpz_class c = linearPow(a, b);

            //TRACE(c);

            UI digitSum = getDigitSum(c);
            maxSum = MAX(digitSum, maxSum);
        }
    }

    return maxSum;
}

int main() {
    cout << solve056();
    return 0;
}
