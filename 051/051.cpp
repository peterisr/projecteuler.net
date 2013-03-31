/**
 * By replacing the 1st digit of *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having
 * seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
 * Consequently 56003, being the first member of this family, is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits)
 * with the same digit, is part of an eight prime value family.
 *
 * @task 051
 * @answer 121313
 */
#include "../projecteuler.h"
#define max (1 * (UI)1e6)

UC getFamilySize(UI prime, UI mask, bool verbose) {
    static primeTester PT(max);
    UI familySize = 0;
    VUI digits = getDigits(prime, 10);

    // All masked digits must be the same
    // otherwise this number does not belong to the family
    UI maskedDigit = 10, mm = mask;
    for(UI j = 0; mm; j++) {
        if (mm & (1 << j)) {
            if (maskedDigit != 10 && maskedDigit != digits[digits.size() - j - 1]) {
                return 0;
            }

            maskedDigit = digits[digits.size() - j - 1];
            mm ^= (1 << j);
        }
    }

    if (verbose) {
        TRACE(prime);
        TRACE(mask);
    }

    FOR(i,0,10) {
        // First digit of a number can't be 0
        if (i == 0 && ((1 << (digits.size() - 1)) & mask)) {
            continue;
        }

        UI m = mask;
        for(UI j = 0; m; j++) {
            if (m & (1 << j)) {
                digits[digits.size() - j - 1] = i;
                m ^= (1 << j);
            }
        }

        UI toTest = 0;
        F(i,digits.size()) {
            toTest *= 10;
            toTest += digits[i];
        }

        if (PT.isPrime(toTest)) {
            if (verbose) {
                TRACE(toTest);
            }

            familySize++;
        }
    }

    return familySize;
}

UI solve051() {
    VUI primes = getPrimeList(max);

    UI digits = 1, tenPower = 10;
    FOR(i,0,primes.size()) {
        if (primes[i] > tenPower) {
            tenPower *= 10;
            digits++;
        }

        UI maxMask = (1 << digits) - 1;
        FOR(mask,1,maxMask) {
            // The last digit can't be in the mask
            // because that would mean that the family contains
            // numbers that end with even digits
            // but those are not prime
            if (mask & 1) {
                continue;
            }

            UC familySize = getFamilySize(primes[i], mask, false);
            if (false) {
                TRACE(primes[i]);
                TRACE(mask);
                TRACE(familySize);
            }
            if (familySize == 8) {
                //getFamilySize(primes[i], mask, true);
                return primes[i];
            }
        }
    }

    return 0;
}

int main() {
    cout << solve051();
    return 0;
}
