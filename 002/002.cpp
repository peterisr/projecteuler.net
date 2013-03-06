/**
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms.
 * By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values
 * do not exceed four million, find the sum of the even-valued terms.
 *
 * @task 002
 * @answer 4613732
 */
#include "../projecteuler.h"

ULL fibonacciEvenElementSum(UI maxElement) {
    ULL result = 0;
    UI a = 1, b = 2, c;
    while (b <= maxElement) {
        if (b % 2 == 0) {
            result += b;
        }

        c = a + b;
        a = b;
        b = c;
    }

    return result;
}

ULL solve002() {
    return fibonacciEvenElementSum(4000000);
}

int main() {
    cout << solve002();
    return 0;
}
