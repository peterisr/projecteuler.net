/**
 * The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
 * (i) each of the three terms are prime, and,
 * (ii) each of the 4-digit numbers are permutations of one another.
 *
 * There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes,
 * exhibiting this property, but there is one other 4-digit increasing sequence.
 *
 * What 12-digit number do you form by concatenating the three terms in this sequence?
 *
 * @task 049
 * @answer 296962999629
 */
#include "../projecteuler.h"

UI vectorTo(const vector<UI> v) {
    UI result = 0;
    F(i,v.size()) {
        result *= 10;
        result += v[i];
    }

    return result;
}

ULL getSuperPermutation(UI prime) {
    static primeTester PT(10000);

    VUI digits = getDigits(prime, 10);
    VUI primePerms;
    primePerms.push_back(prime);

    while (moveToNextPermutation(digits)) {
        if (PT.isPrime(vectorTo(digits))) {
            primePerms.push_back(vectorTo(digits));
        }
    }

    FOR(j,0,primePerms.size()) {
        FOR(k,j+1,primePerms.size()) {
            UI d1 = primePerms[j] - prime;
            UI d2 = primePerms[k] - primePerms[j];
            if (d1 == d2) {
                ULL result = prime;
                result *= 10000;
                result += primePerms[j];
                result *= 10000;
                result += primePerms[k];
                return result;
            }
        }
    }

    return 0;
}

ULL solve049() {
    ULL result = 0;
    VUI primes = getPrimeList(10000);
    F(i,primes.size()) {
        if (primes[i] < 1000) {
            continue;
        }

        ULL perm = getSuperPermutation(primes[i]);
        if (perm && primes[i] != 1487) {
            //TRACE(primes[i]);
            //TRACE(perm);
            result = perm;
        }
    }

    return result;
}

int main() {
    cout << solve049();
    return 0;
}
