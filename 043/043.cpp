/**
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9
 * in some order, but it also has a rather interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:
 *
 *     d2d3d4=406 is divisible by 2
 *     d3d4d5=063 is divisible by 3
 *     d4d5d6=635 is divisible by 5
 *     d5d6d7=357 is divisible by 7
 *     d6d7d8=572 is divisible by 11
 *     d7d8d9=728 is divisible by 13
 *     d8d9d10=289 is divisible by 17
 *
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 *
 * @task 043
 * @answer 16695334890
 */
#include "../projecteuler.h"

bool hasWeirdProperty(const string &s) {
    return (
        ((s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0')) % 2 == 0
        && ((s[2] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0')) % 3 == 0
        && ((s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0')) % 5 == 0
        && ((s[4] - '0') * 100 + (s[5] - '0') * 10 + (s[6] - '0')) % 7 == 0
        && ((s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0')) % 11 == 0
        && ((s[6] - '0') * 100 + (s[7] - '0') * 10 + (s[8] - '0')) % 13 == 0
        && ((s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0')) % 17 == 0
    );
}

ULL solve043() {
    ULL result = 0;

    string perm = "0123456789";
    string end = "9876543210";

    do {
        if (hasWeirdProperty(perm)) {
            TRACE(perm);
            result += stringTo(perm);
        }
    } while (perm != end && moveToNextPermutation(perm));

    return result;
}

int main() {
    cout << solve043();
    return 0;
}
