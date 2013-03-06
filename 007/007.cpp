/**
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 *
 * @task 007
 * @answer 104743
 */
#include "../projecteuler.h"

UI solve007() {
    UI which = 10001;
    primeTester PT(1 * 1000 * 1000);

    UI n = 1, num = 2;
    while (n++ < which) {
        while (!PT.isPrime(++num));
    }

    return num;
}

int main() {
    cout << solve007();
    return 0;
}
