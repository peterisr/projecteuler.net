/**
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * @task 004
 * @answer 906609
 */
#include "../projecteuler.h"

bool isPalindrome(UI a) {
    VUI digits;
    while (a) {
        digits.push_back(a % 10);
        a /= 10;
    }

    int i = 0, j = digits.size() - 1;
    while (i < j) {
        if (digits[i] != digits[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

UI solve004() {
    UI max = 0;

    for (UI a = 100; a < 1000; a++) {
        for (UI b = a; b < 1000; b++) {
            UI c = a * b;
            if (isPalindrome(c)) {
                max = MAX(max, c);
            }
        }
    }

    return max;
}

int main() {
    cout << solve004();
    return 0;
}
