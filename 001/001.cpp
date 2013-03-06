/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * @task 001
 * @answer 233168
 */
#include "../projecteuler.h"

UI countWithArithmeticProgression()
{
    UI a = 3 * (1 + 333) * 333 / 2;
    UI b = 5 * (1 + 199) * 199 / 2;
    UI c = 15 * (1 + 990/15) * (990/15) / 2;
    UI result = a + b - c;
    return result;
}

UI countBruteForce(UI to = 1000)
{
    UI result = 0;
    for (UI i = 1; i < to; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            result += i;
        }
    }

    return result;
}

UI solve001() {
    return countWithArithmeticProgression();
}

int main() {
    cout << solve001();
    return 0;
}
