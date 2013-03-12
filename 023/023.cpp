/**
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
 * For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
 * By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
 * However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that
 * cannot be expressed as the sum of two abundant numbers is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 *
 * @task 023
 * @answer 4179871
 */
#include "../projecteuler.h"

bool checkIfIsAbundant(UI number, UI max) {
    VI divisors = getAllDistinctDivisors(number);

    UI sum = 0;
    F(j,divisors.size()) {
        sum += divisors[j];
    }
    sum -= number;

    return (sum > number);
}

UI solve023() {
    const UI to = 28123;

    VI abundant;
    FOR(i,1,to + 1) {
        if (checkIfIsAbundant(i, to)) {
            abundant.push_back(i);
        }
    }

    bool isExpressable[to + 1];
    memset(isExpressable, 0, sizeof isExpressable);
    F(i,abundant.size()) {
        for (UI j = i; j < abundant.size() && abundant[i] + abundant[j] <= to; j++) {
            isExpressable[abundant[i] + abundant[j]] = true;
        }
    }

    UI sum = 0;
    FOR(i,1,to) {
        if (!isExpressable[i]) {
            //TRACE(i);
            sum += i;
        }
    }

    return sum;
}

int main() {
    cout << solve023();
    return 0;
}
