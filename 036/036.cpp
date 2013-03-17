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

bool isDoublePalindomic(UI number) {
    return (
        isPalindome(number, (UI)10)
        && isPalindome(number, (UI)2)
    );
}

ULL solve036() {
    ULL sum = 0;

    FOR(i,1,1000 * 1000) {
        if (isDoublePalindomic(i)) {
            //TRACE(i);
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << solve036();
    return 0;
}
