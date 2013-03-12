/**
 * n! means n x (n − 1) ... 3 x 2 x 1
 *
 * For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 *
 * Find the sum of the digits in the number 100!
 *
 * @task 020
 * @answer 648
 */
#include "../projecteuler.h"

UI solve020() {
    mpz_class factorial = 1;
    FOR(i,1,101) {
        factorial *= i;
    }

    UI sum = 0;
    while (factorial > 0) {
        mpz_class digit = (factorial % 10);
        factorial /= 10;
        sum += digit.get_ui();
    }

    return sum;
}

int main() {
    cout << solve020();
    return 0;
}
