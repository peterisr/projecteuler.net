/**
 *
 * The number, 197, is called a circular prime because
 * all rotations of the digits: 197, 971, and 719, are
 * themselves prime.
 *
 * There are thirteen such primes below 100:
 * 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 *
 * How many circular primes are there below one million?
 *
 * @task 035
 * @answer 55
 */
#include "../projecteuler.h"

bool isCircularPrime(UI number) {
    static primeTester PT(1000*1000);

    VI digits;
    while (number) {
        digits.push_back(number % 10);
        number /= 10;
    }

    UI ds = digits.size();
    FOR(i,0,ds) {
        UI test = 0;
        UI j = i;
        do {
            test *= 10;
            test += digits[j];
            j = (j + 1) % ds;
        } while (j != i);

        if (!PT.isPrime(test)) {
            return false;
        }
    }

    return true;
}

UI solve035() {
    UI count = 0;

    FOR(i,1,1000*1000) {
        if (isCircularPrime(i)) {
            //TRACE(i);
            count++;
        }
    }

    return count;
}

int main() {
    cout << solve035();
    return 0;
}
