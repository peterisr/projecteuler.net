/**
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a != b, then a and b are
 * an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
 * The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 * @task 021
 * @answer 31626
 */
#include "../projecteuler.h"

UI getD(UI num) {
    UI sum = 0;
    VI divisors = getAllDistinctDivisors(num);
    F(i,divisors.size()) {
        sum += divisors[i];
    }

    sum -= num;
    return sum;
}

UI solve021() {
    const UI to = 10000;
    UI D[to + 1];
    FOR(i,1,to + 1) {
        D[i] = getD(i);
    }

    UI sum = 0, max = 0;
    FOR(i,1,to + 1) {
        max = MAX(max, D[i]);
        if (D[i] < to && D[D[i]] == i && D[i] != i) {
            //TRACE(i);
            sum += i;
        }
    }

    //TRACE(max);
    return sum;
}

int main() {
    cout << solve021();
    return 0;
}
