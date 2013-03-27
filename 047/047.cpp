/**
 * The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 x 7
 * 15 = 3 x 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 *
 * 644 = 2^2 x 7 x 23
 * 645 = 3 x 5 x 43
 * 646 = 2 x 17 x 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors.
 * What is the first of these numbers?
 *
 * @task 047
 * @answer 134043
 */
#include "../projecteuler.h"

bool check(UI number) {
//    TRACE(number);
    FOR(i,0,4) {
        vector< pair<UI, UI> > factors = getPrimeFactors(number + i);

//        FOREACH (iter, factors) {
//            TRACE(iter->first);
//        }

        if (factors.size() != 4) {
            return false;
        }
    }

    return true;
}

UI solve047() {
    UI i = 1;

    while (!check(i)) {
        i++;
    }

    return i;
}

int main() {
    cout << solve047();
    return 0;
}
