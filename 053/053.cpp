/**
 * There are exactly ten ways of selecting three from five, 12345:
 *
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, 5C3 = 10.
 *
 * In general,
 * nCr = n! / r!(n−r)!
 * ,where r <= n, n! = nx(n−1)x...x3x2x1, and 0! = 1.
 *
 * It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
 *
 * How many, not necessarily distinct, values of  nCr, for 1 <= n <= 100, are greater than one-million?
 *
 * @task 053
 * @answer 4075
 */
#include "../projecteuler.h"

UI solve053() {
    const UI to = 100;
    UI cnt = 0;

    FOR(n,1,to + 1) {
        UI c = 1, bigger = 0;
        FOR(r,1,n) {
            c *= (n - r + 1);
            c /= r;
            if (c > 1000 * 1000) {
                bigger = r;
                break;
            }
        }

        UI biggerCount = 0;
        if (bigger > 0) {
            biggerCount = (n + 1 - 2 * bigger);
        }

        //TRACE(n);
        //TRACE(biggerCount);

        cnt += biggerCount;
    }

    return cnt;
}

int main() {
    cout << solve053();
    return 0;
}
