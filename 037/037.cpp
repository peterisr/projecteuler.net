/**
 * The number 3797 has an interesting property. Being prime itself, it is possible to
 * continuously remove digits from left to right, and remain prime at each stage:
 * 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and
 * 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to right
 * and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 *
 * @task 037
 * @answer 748317
 */
#include "../projecteuler.h"

bool isTruncatable(const VUI &num) {
    static primeTester PT(10 * 1000 * 1000);

    // left to right
    int i = 0;
    UI test = 0;
    while (i < num.size()) {
        test *= 10;
        test += num[i];
        if (!PT.isPrime(test)) {
            return false;
        }
        i++;
    }

    // right to left
    i = num.size() - 1;
    UI next = 1;
    test = 0;
    while (i >= 0) {
        test += next * num[i];
        if (!PT.isPrime(test)) {
            return false;
        }
        i--;
        next *= 10;
    }

    return true;
}

VUI toVector(UI num) {
    VUI v;

    while (num) {
        v.push_back(num % 10);
        num /= 10;
    }

    UI j = v.size() - 1, i = 0;
    while (i < j) {
        UI tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        j--;
        i++;
    }

    return v;
}

ULL toULL(const VUI &num) {
    ULL r = 0;
    F(i,num.size()) {
        r *= 10;
        r += num[i];
    }

    return r;
}

ULL solve037() {
    ULL sum = 0;
    UI found = 0, middle = 0, middlePower = 10, front[] = {2,3,5,7}, back[] = {3,7};

    while (found < 11) {
        F(f,4) {
            F(b,2) {
                UI num = front[f];

                if (middle > 0) {
                    num *= middlePower;
                    num += middle;
                }

                num *= 10;
                num += back[b];
                if (isTruncatable(toVector(num))) {
                    sum += num;
                    found++;
                    //TRACE(num);
                }
            }
        }

        middle++;
        if (
            middle == 10
            || middle == 100
            || middle == 1000
            || middle == 10000
            || middle == 100000
            || middle == 1000000
        ) {
            middlePower *= 10;
        }
    }

    return sum;
}

int main() {
    cout << solve037();
    return 0;
}
