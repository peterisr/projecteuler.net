/**
 * The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 *
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 *
 * @task 048
 * @answer 9110846700
 */
#include "../projecteuler.h"

ULL solve048() {
    const ULL mod = 10ull * 1000ull * 1000ull * 1000ull;
    const UI to = 1000;

    ULL sum = 0;
    FOR(i,1,to + 1) {

        ULL p = i;
        FOR(j,1,i) {
            p *= i;
            p %= mod;
        }

        sum += p;
        sum %= mod;
    }

    return sum;
}

int main() {
    cout << solve048();
    return 0;
}
