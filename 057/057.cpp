/**
 * It is possible to show that the square root of two can be expressed as an infinite continued fraction.
 *
 * sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
 *
 * By expanding this for the first four iterations, we get:
 *
 * 1 + 1/2 = 3/2 = 1.5
 * 1 + 1/(2 + 1/2) = 7/5 = 1.4
 * 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
 * 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
 *
 * The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985,
 * is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.
 *
 * In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
 *
 * @task 057
 * @answer 153
 */
#include "../projecteuler.h"

UI solve057() {
    const UI to = 1000;
    UI count = 0;

    mpz_class numerator = 3, nTP = 10;
    mpz_class denominator = 2, dTP = 10;
    FOR(i,1,to) {
        numerator = denominator + numerator;
        swap(numerator, denominator);
        numerator = denominator + numerator;

        if (numerator > nTP) {
            nTP *= 10;
        }

        if (denominator > dTP) {
            dTP *= 10;
        }

        if (nTP > dTP) {
            count++;
        }

        //cout << numerator << " / " << denominator << endl;
    }

    return count;
}

int main() {
    cout << solve057();
    return 0;
}
