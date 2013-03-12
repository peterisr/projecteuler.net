#ifndef PROJECTEULER_CODE
#define PROJECTEULER_CODE 1

#include "projecteuler.h"

/**
 * Given an array of bytes,
 * manipulate the n-th bit.
 *
 * Used for saving memory.
 *
 * The *16 functions are specifically for Sieve of Eratosthenes
 * to ignore even numbers and save some more memory.
 */
#define GETBITINBYTEARRAY(array, n) (array[n / 8] & (((UC)1) << (n % 8)))
#define SET0BITINBYTEARRAY(array, n) (array[n / 8] = (array[n / 8] & (~(((UC)1) << (n % 8)))))
#define SET1BITINBYTEARRAY(array, n) (array[n / 8] = (array[n / 8] | (((UC)1) << (n % 8))))

#define GETBITINBYTEARRAY16(array, n) (array[n / 16] & (((UC)1) << ((n / 2) % 8)))
#define SET0BITINBYTEARRAY16(array, n) (array[n / 16] = (array[n / 16] & (~(((UC)1) << ((n / 2) % 8)))))
#define SET1BITINBYTEARRAY16(array, n) (array[n / 16] = (array[n / 16] | (((UC)1) << ((n / 2) % 8))))

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
 * Get all distinct divisors of given number N.
 * Divisors are returned in ascending order.
 *
 * @param UI N
 * @return vector of UI
 */
VI getAllDistinctDivisors(UI N) {
    vector < pair<UI, UI> > primeFactors = getPrimeFactors(N);
    VI result;
    for (UI i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            UI other = N / i;
            if (other == i) {
                result.push_back(other);
            } else {
                result.push_back(other);
                result.push_back(i);
            }
        }
    }

    sort(result.begin(), result.end());
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
 * Also, don't store even numbers.
 */
class primeTester
{
    private:
        UI N, bytes;
        UC *isPrimeTable;

    public:
        primeTester(UI maxNumberToTest) {
            N = maxNumberToTest;

            bytes = N / 16 + 2;
            isPrimeTable = new UC[bytes];
            for (UI i = 0; i < bytes; i++) {
                isPrimeTable[i] = (UC)255;
            }

            SET0BITINBYTEARRAY16(isPrimeTable, 1);
            for (UI i = 3; i * i <= N; i += 2) {
                if (!GETBITINBYTEARRAY16(isPrimeTable, i)) {
                    continue;
                }

                for (UI j = i + i + i; j <= N; j += i + i) {
                    SET0BITINBYTEARRAY16(isPrimeTable, j);
                }
            }
        }

        ~primeTester() {
            delete [] isPrimeTable;
        }

        bool isPrime(UI number) {
            if (number % 2 == 0) {
                return (number == 2);
            } else {
                return GETBITINBYTEARRAY16(isPrimeTable, number);
            }
        }
};

/**
 * Get vector of all primes <= N.
 * @param UI max number
 * @return vector of UI
 */
vector<UI> getPrimeList(UI N) {
    primeTester PT(N);
    vector<UI> result;

    UI c = 0;
    FORE(i,1,N) {
        if (PT.isPrime(i)) {
            result.push_back(i);
        }
    }

    return result;
}



/**
 * Is the given year a leap year?
 * @param UI year
 * @return bool
 */
bool isLeapYear(UI year) {
    return (
        year % 4 == 0
        && (year % 100 != 0 || year % 400 == 0)
    );
}

/**
 * Return # of days in month.
 * @param UI year
 * @param UI number of month 1..12
 * @return UI
 */
UI getDaysInMonth(UI year, UI month) {
    static UI monthDays[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    return (isLeapYear(year) && month == 2) ? 29 : monthDays[month - 1];
}

/**
 * Get next permutation of string in lexicographic order.
 * @param string & the permutation in it's current state.
 * @param int length - length of permutation
 * @return bool were we able to get the next permutation.
 * False, when the current permutation is already the last.
 * E.g. "9876543210".
 */
bool moveToNextPermutation(string &permutation) {
    auto iter = permutation.end();
    iter--;
    int i = permutation.size() - 1;
    while (i > 0 && permutation[i - 1] > permutation[i]) {
        i--;
        iter--;
    }

    if (i == 0) {
        return false;
    }

    int minPos = i;
    FOR(j,i,permutation.size()) {
        if (permutation[j] > permutation[i - 1] && permutation[j] < permutation[minPos]) {
            minPos = j;
        }
    }

    swap(permutation[i - 1], permutation[minPos]);

    //TRACE(i - 1);
    //TRACE(minPos);

    // sort reminder for minimal permutation
    sort(iter, permutation.end());
    return true;
}

#endif // PROJECTEULER_CODE
