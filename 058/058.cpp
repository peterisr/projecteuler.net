/**
 * Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.
 *
 * 37 36 35 34 33 32 31
 * 38 17 16 15 14 13 30
 * 39 18  5  4  3 12 29
 * 40 19  6  1  2 11 28
 * 41 20  7  8  9 10 27
 * 42 21 22 23 24 25 26
 * 43 44 45 46 47 48 49
 *
 * It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting
 * is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.
 *
 * If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed.
 * If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
 *
 * @task 058
 * @answer 26241
 */
#include "../projecteuler.h"

UI solve058() {
    const UI max = (UI)1e9;
    static primeTester PT(max);

    UI diagonalElementCount = 1,
       primes = 0,
       exitValue = 1,
       sideLength = 1;

    do {
        diagonalElementCount += 4;
        sideLength += 2;
        exitValue = sideLength * sideLength;
        //TRACE(exitValue - 3 * (sideLength - 1));

        if (PT.isPrime(exitValue - (sideLength - 1))) {
            primes++;
        }

        if (PT.isPrime(exitValue - 2 * (sideLength - 1))) {
            primes++;
        }

        if (PT.isPrime(exitValue - 3 * (sideLength - 1))) {
            primes++;
        }
    } while (diagonalElementCount < 10 * primes);

    return sideLength;
}

int main() {
    cout << solve058();
    return 0;
}
