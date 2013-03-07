/**
 * The prime 41, can be written as the sum of six consecutive primes:
 *    41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most consecutive primes?
 *
 * @task 050
 * @answer 997651
 */
#include "../projecteuler.h"

UI solve050() {
    const UI N = 1000000;
    primeTester PT(N);
    VUI primes = getPrimeList(N);

    UI size = primes.size(), max = 0, prime;
    F(i,size) {
        UI s = 0, j = i, cnt = 0;
        while (j < size && s < N) {
            s += primes[j++];
            cnt++;
            if (s < N && cnt > max && PT.isPrime(s)) {
                max = cnt;
                prime = s;
            }
        }
    }

    return prime;
}

int main() {
    cout << solve050();
    return 0;
}
