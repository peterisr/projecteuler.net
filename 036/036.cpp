/**
 * The decimal number, 585 = 1001001001 (binary),
 * is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million,
 * which are palindromic in base 10 and base 2.
 *
 * (Please note that the palindromic number, in either
 * base, may not include leading zeros.)
 *
 * @task 036
 * @answer 872187
 */
#include "../projecteuler.h"

bool isPalindomicDecimal(UI number) {
    VI digits;

    while (number) {
        digits.push_back(number % 10);
        number /= 10;
    }

    UI l = 0, r = digits.size() - 1;
    while (l < r && digits[l] == digits[r]) {
        l++;
        r--;
    }

    return (l >= r);
}

bool isPalindomicBinary(UI number) {
    UI l = 23;

    while (!(number & (1 << l))) {
        l--;
    }

    UI r = 0;
    while (l > r && !!(number & (1 << l)) == !!(number & (1 << r))) {
        l--;
        r++;
    }

    return (l <= r);
}

bool isDoublePalindomic(UI number) {
    return (
        isPalindomicDecimal(number)
        && isPalindomicBinary(number)
    );
}

ULL solve036() {
    ULL sum = 0;

    FOR(i,1,1000 * 1000) {
        if (isDoublePalindomic(i)) {
            TRACE(i);
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << solve036();
    return 0;
}
