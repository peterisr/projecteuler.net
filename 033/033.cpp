/**
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in
 * attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is
 * correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less than one
 * in value, and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, find
 * the value of the denominator.
 *
 * @task 033
 * @answer 100
 */
#include "../projecteuler.h"

bool isCuriousForDigit(UI numerator, UI denominator, UI digit) {
    if (
        digit == 0
        || denominator * digit % numerator != 0
        || !(getDigitMask(digit) & getDigitMask(denominator))
    ) {
        return false;
    }

    UI top = (numerator % 10 == digit) ? (numerator / 10) : (numerator % 10);
    UI bottom = denominator * top / numerator;

    if (
        getDigitCount(bottom) != 1
        || bottom == digit
        || !(getDigitMask(denominator) & getDigitMask(bottom))
        || (bottom * numerator != top * denominator)
    ) {
        return false;
    }

    return true;
}

bool isCurious(UI numerator, UI denominator) {
    return (
           isCuriousForDigit(numerator, denominator, numerator / 10)
        || isCuriousForDigit(numerator, denominator, numerator % 10)
    );
}

UI solve033() {
    UI multiDenominator = 1, multiNumerator = 1;
    FOR(denominator,11,100) {
        FOR (numerator,10,denominator) {
            if (isCurious(numerator, denominator)) {
                if (true) {
                    TRACE(numerator);
                    TRACE(denominator);
                }

                multiDenominator *= denominator;
                multiNumerator *= numerator;
            }
        }
    }

    UI gcd = getGCD(multiDenominator, multiNumerator);
    return multiDenominator / gcd;
}

int main() {
    cout << solve033();
    return 0;
}
