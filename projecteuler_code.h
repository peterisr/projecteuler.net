#ifndef PROJECTEULER_CODE
#define PROJECTEULER_CODE 1

#include "projecteuler.h"

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

#endif // PROJECTEULER_CODE
