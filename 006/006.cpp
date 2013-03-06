/**
 * The sum of the squares of the first ten natural numbers is,
 *    1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *    (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first
 *    ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 * Find the difference between the sum of the squares of the first one
 *    hundred natural numbers and the square of the sum.
 *
 * @task 006
 * @answer 25164150
 */
#include "../projecteuler.h"

UI solve006() {
    UI to = 100;

    UI a = to * (to + 1) * (2 * to + 1) / 6;
    UI b = (to + 1) * to / 2;
    b *= b;

    return (b - a);
}

int main() {
    cout << solve006();
    return 0;
}
