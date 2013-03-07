/**
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *    a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 2^5 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *
 * Find the product abc.
 *
 * @task 009
 * @answer 31875000
 */
#include "../projecteuler.h"

UI solve009() {
    int a, b, c;
    const int FK = 500 * 1000;

    for (b = 1; b < 1000; b++) {
        if ((1000 * (b - 500)) % (b - 1000) == 0) {
            a = (1000 * (b - 500)) / (b - 1000);
            c = sqrt(a * a + b * b);
            break;
        }
    }

    //cout << "(" << a << ", " << b << ", " << c << ")" << endl;
    return (UI)(a * b * c);
}

int main() {
    cout << solve009();
    return 0;
}
