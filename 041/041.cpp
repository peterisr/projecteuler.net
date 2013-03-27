/**
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
 * For example, 2143 is a 4-digit pandigital and is also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 *
 * @task 041
 * @answer 7652413
 */
#include "../projecteuler.h"

UI solve041() {
    UI result = 0;
    string digitsL2H = "", digitsH2L = "";
    char digit[1];

    FOR(i,1,10) {
        digit[0] = ((char)i + '0');
        digitsL2H += string(digit);
        digitsH2L = string(digit) + digitsH2L;
        //TRACE(digitsL2H);
        //TRACE(digitsH2L);
        string perm = digitsL2H;
        do {
            if (isPrime(stringTo(perm))) {
                //TRACE(perm);
                result = stringTo(perm);
            }
        } while (perm != digitsH2L && moveToNextPermutation(perm));
    }

    return result;
}

int main() {
    cout << solve041();
    return 0;
}
