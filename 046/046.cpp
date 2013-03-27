/**
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
 *
 * 9 = 7 + 2x12
 * 15 = 7 + 2x22
 * 21 = 3 + 2x32
 * 25 = 7 + 2x32
 * 27 = 19 + 2x22
 * 33 = 31 + 2x12
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
 *
 * @task 046
 * @answer 5777
 */
#include "../projecteuler.h"

UI isSquare(UI number) {
    UI t = 0;
    for(UI i = (1 << 15); i >= 1; i >>= 1) {
        UI tmp = (i | t);
        tmp *= tmp;

        if (tmp <= number) {
            t = (i | t);
        }
    }

    return (number == t * t);
}

UI solve046() {
    const UI assumption = 1000 * 1000;
    primeTester PT(assumption);
    VUI primes = getPrimeList(assumption);

    for(UI i = 3; i < assumption; i += 2) {
        if (PT.isPrime(i)) {
            continue;
        }

        bool ok = false;
        UI j = 1;
        while (!ok && primes[j] < i) {
            if (isSquare((i - primes[j]) / 2)) {
                ok = true;
            }

            j++;
        }

        if (!ok) {
            return i;
        }
    }

    TRACE("FAIL");
    return 0;
}

int main() {
    cout << solve046();
    return 0;
}
