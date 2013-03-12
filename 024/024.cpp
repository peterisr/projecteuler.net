/**
 * A permutation is an ordered arrangement of objects.
 * For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 *
 * 012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 *
 * @task 024
 * @answer 2783915460
 */
#include "../projecteuler.h"

ULL solve024() {
    const UI to = 1000000;

    UI permutation = 1;
    string perm("0123456789");
    while (permutation++ < to) {
        moveToNextPermutation(perm);
    }

    ULL res = 0;
    F(i,perm.size()) {
        res *= 10;
        res += (perm[i] - '0');
    }

    return res;
}

int main() {
    cout << solve024();
    return 0;
}
