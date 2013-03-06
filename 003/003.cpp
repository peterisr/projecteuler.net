/**
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * @task 003
 * @answer 6857
 */
#include "../projecteuler.h"

typedef vector< pair<ULL, UI> > VPULL;

ULL solve003() {
    // Get all factors of number
    VPULL factors = getPrimeFactors((ULL)(600851475143));

    // Get the maximum
    ULL max = 0;
    FOREACH(iter, factors) {
        max = MAX(iter->first, max);
    }

    return max;
}

int main() {
    cout << solve003();
    return 0;
}
