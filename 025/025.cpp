/**
 * The Fibonacci sequence is defined by the recurrence relation:
 *
 *     Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 *
 * Hence the first 12 terms will be:
 *
 *     F1 = 1
 *     F2 = 1
 *     F3 = 2
 *     F4 = 3
 *     F5 = 5
 *     F6 = 8
 *     F7 = 13
 *     F8 = 21
 *     F9 = 34
 *     F10 = 55
 *     F11 = 89
 *     F12 = 144
 *
 * The 12th term, F12, is the first term to contain three digits.
 *
 * What is the first term in the Fibonacci sequence to contain 1000 digits?
 *
 * @task 025
 * @answer 4782
 */
#include "../projecteuler.h"

UI incrementalNumberLength(const mpz_class &num) {
    static mpz_class a = 10;
    static UI ret = 1;

    while (a < num) {
        a *= 10;
        ret++;
    }

    return ret;
}

UI solve025() {
    UI to = 1000;

    mpz_class a = 1, b = 1, tmp;
    UI term = 2;

    while (incrementalNumberLength(b) < to) {
        tmp = b;
        b = a + b;
        a = tmp;
        term++;
        //TRACE(b);
    }

    return term;
}

int main() {
    cout << solve025();
    return 0;
}
