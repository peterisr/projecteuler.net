/**
 * Euler published the remarkable quadratic formula:
 *    n^2 + n + 41
 * It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39.
 * However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when
 * n = 41, 41^2 + 41 + 41 is clearly divisible by 41.
 *
 * Using computers, the incredible formula  n^2 − 79n + 1601 was discovered, which produces 80 primes
 * for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
 *
 * Considering quadratics of the form:
 *    n^2 + an + b, where |a| < 1000 and |b| < 1000
 *    where |n| is the modulus/absolute value of n
 *    e.g. |11| = 11 and |−4| = 4
 *
 * Find the product of the coefficients, a and b, for the quadratic expression
 * that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 *
 * @task 027
 * @answer -59231
 */
#include "../projecteuler.h"

int solve027() {
    primeTester PT(10 * 1000 * 1000);
    cout << "primeTester initialized;" << endl;

    int result, maxCount = 0;
    for (int a = -1000; a <= 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0, count = -1, val;
            do {
                val = n * n + a * n + b;
                n++;
                count++;
            } while (val > 0 && PT.isPrime(val));

            if (count > maxCount) {
                result = a * b;
                maxCount = count;
                //cout << "count = " << count << " for a = " << a << "; b = " << b << endl;
            }
        }
    }

    return result;
}

int main() {
    cout << solve027();
    return 0;
}
