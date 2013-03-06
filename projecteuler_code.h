#ifndef PROJECTEULER_CODE
#define PROJECTEULER_CODE 1

#include "projecteuler.h"

/**
 * Given an array of bytes,
 * manipulate the n-th bit.
 *
 * Used for saving memory.
 */
#define GETBITINBYTEARRAY(array, n) (array[n / 8] & (((UC)1) << (n % 8)))
#define SET0BITINBYTEARRAY(array, n) (array[n / 8] = (array[n / 8] & (~(((UC)1) << (n % 8)))))
#define SET1BITINBYTEARRAY(array, n) (array[n / 8] = (array[n / 8] | (((UC)1) << (n % 8))))

/**
 * Get all distinct prime factors of a number,
 * and their maximum power.
 *
 * @param the number
 * @return vector of pairs, where the first element in each pair is the factor,
 *    second is the maximum power
 */
template <class T>
vector < pair<T, UI> > getPrimeFactors(T number) {
    vector < pair<T, UI> > result;
    map<T, pair<T, UI> *> mapping;

    T iter = 2;
    while (iter * iter <= number) {
        if (number % iter == 0) {
            if (INMAP(mapping, iter)) {
                mapping[iter]->second++;
            } else {
                result.push_back(make_pair(iter, 1));
                mapping[iter] = &result.back();
            }
            number /= iter;
            iter = 2;
        } else {
            iter++;
        }
    }

    if (number > 1) {
        if (INMAP(mapping, number)) {
            mapping[number]->second++;
        } else {
            result.push_back(make_pair(number, 1));
        }
    }

    return result;
}

/**
 * Prime tester class. This class is useful if one needs to run
 * primality tests may times for numbers smaller than given N.
 *
 * This class first generates a Sieve of Eratosthenes
 * for a particular N.
 *
 * Then it can be used to check if a number M is a prime
 * in O(1) time if M <= N.
 *
 * Uses one bit of memory for each number <= N.
 */
class primeTester
{
    private:
        UI N, bytes;
        UC *isPrimeTable;

    public:
        primeTester(UI maxNumberToTest) {
            N = maxNumberToTest;

            bytes = N / 8 + 2;
            isPrimeTable = new UC[bytes];
            for (UI i = 0; i < bytes; i++) {
                isPrimeTable[i] = (UC)255;
            }

            SET0BITINBYTEARRAY(isPrimeTable, 1);
            for (UI i = 2; i * i <= N; i++) {
                if (!GETBITINBYTEARRAY(isPrimeTable, i)) {
                    continue;
                }

                for (UI j = i + i; j <= N; j += i) {
                    SET0BITINBYTEARRAY(isPrimeTable, j);
                }
            }
        }

        ~primeTester() {
            delete [] isPrimeTable;
        }

        bool isPrime(UI number) {
            return GETBITINBYTEARRAY(isPrimeTable, number);
        }
};

#endif // PROJECTEULER_CODE
