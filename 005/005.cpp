/**
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 * @task 005
 * @answer 232792560
 */
#include "../projecteuler.h"

ULL solve005() {
    ULL result = 1;
    result *= 2;
    result *= 3;
    result *= 2;
    result *= 5;
    result *= 7;
    result *= 2;
    result *= 3;
    result *= 11;
    result *= 13;
    result *= 2;
    result *= 17;
    result *= 19;
    return result;
}

int main() {
    cout << solve005();
    return 0;
}
