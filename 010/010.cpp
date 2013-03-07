/**
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 *
 * @task 010
 * @answer 142913828922
 */
#include "../projecteuler.h"

ULL solve010() {
    const UI max = 2 * 1000 * 1000;
    primeTester PT(max);

    ULL sum = 0;
    for (UI n = 2; n <= max; n++) {
        if (PT.isPrime(n)) {
            sum += n;
        }
    }

    return sum;
}

int main() {
    cout << solve010();
    return 0;
}
