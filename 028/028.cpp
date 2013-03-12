/**
 * Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 *
 * 21 22 23 24 25
 * 20  7  8  9 10
 * 19  6  1  2 11
 * 18  5  4  3 12
 * 17 16 15 14 13
 *
 * It can be verified that the sum of the numbers on the diagonals is 101.
 *
 * What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
 *
 * @task 028
 * @answer 669171001
 */
#include "../projecteuler.h"

ULL solve028() {
    const UI to = 1001;

    ULL result = 1;
    for(UI i = 3; i <= to; i += 2) {
        result += i * i;
        result += (i - 2) * (i - 2) + i - 1;
        result += (i - 2) * (i - 2) + 2 * (i - 1);
        result += (i - 2) * (i - 2) + 3 * (i - 1);
    }

    return result;
}

int main() {
    cout << solve028();
    return 0;
}
