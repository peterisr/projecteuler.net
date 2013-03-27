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

/**
 * Get the n-th power of an integer.
 * @param T base
 * @param T power
 * @return T
 */
template <class T>
T pow(T base, T power) {
    if (power == 0) {
        return (T)1;
    } else if (power == 1) {
        return base;
    }

    T tmp = pow(base, power / 2);
    tmp *= tmp;

    if (power % 2 != 0) {
        tmp *= base;
    }

    return tmp;
}

/**
 * Get the sum of n-th powers of all number digits.
 * @param T the number
 * @param T power
 * @return T
 */
template <class T>
T sumOfDigitPowers(T number, T power) {
    T result = 0;

    while (number > 0) {
        T digit = number % 10;
        number /= 10;
        result += pow(digit, power);
    }

    return result;
}

/**
 * Get the count of digits in number (base 10).
 * @param T number
 * @return UI digit count
 */
template <class T>
UI getDigitCount(T number) {
    if (number == 0) {
        return 1;
    }

    UI count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }

    return count;
}

/**
 * Which digits are used in the given number?
 * Returns a bitmask where bit 1 means that i-th
 * digit is present in the number.
 * Only 10 least-significant bits are used in the return value.
 * @param T number
 * @return UI mask
 */
template <class T>
UI getDigitMask(T number) {
    UI mask = 0;

    if (number == 0) {
        return 1;
    }

    while (number > 0) {
        UI digit = number % 10;
        number /= 10;
        mask |= (1 << digit);
    }

    return mask;
}

/**
 * Get the greatest common devisor of two integers.
 * @param T first integer
 * @param T second integer
 * @return the greatest common devisor of both given integers
 */
template <class T>
T getGCD(T a, T b) {
    T tmp;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}


/**
 * Check if given number (> 0) is a palindome in given base (> 1).
 * @param T number
 * @param T base
 * @return true if is palindrome
 */
template <class T>
bool isPalindome(T number, T base) {
    T reverse = 0;

    UI iter = number;
    while (iter) {
        reverse *= base;
        reverse += iter % base;
        iter /= base;
    }

    return (reverse == number);
}


/**
 * Split the number ito digits in a given base.
 * @param T number
 * @param UI base
 * @return vector of UI
 */
template <class T>
VUI getDigits(T number, UI base) {
    VUI digits;
    if (number == 0) {
        digits.push_back(0);
        return digits;
    }

    while (number) {
        digits.insert(digits.begin(), number % base);
        number /= base;
    }

    return digits;
}

/**
 * Convert a string of digits into a ULL / UI.
 * Useful together with, for example, moveToNextPermutation.
 * @param string
 * @return T
 */
ULL stringTo(const string &s) {
    ULL result = 0;

    if (s.size() == 0) {
        return result;
    }

    UI i = 0;
    if (s[0] == '-' || s[0] == '+') {
        i++;
    }

    while (i < s.size()) {
        result *= 10;
        result += (s[i] - '0');
        i++;
    }

    if (s[0] == '-') {
        result *= -1;
    }

    return result;
}

/**
 * Test wether a single number is / is not a prime.
 * @param T the number
 * @return bool
 */
template <class T>
bool isPrime(T number) {
    if (number == 2) {
        return true;
    }

    if (number == 0 || number == 1 || number % 2 == 0) {
        return false;
    }

    T iter = 3;
    while (iter * iter <= number) {
        if (number % iter == 0) {
            return false;
        }

        iter += 2;
    }

    return true;
}

#endif // PROJECTEULER_CODE
