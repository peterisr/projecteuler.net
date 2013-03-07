/**
 * The following iterative sequence is defined for the set of positive integers:
 *     n -> n/2 (n is even)
 *     n -> 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *     13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
 * Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 * @task 014
 * @answer 837799
 */
#include "../projecteuler.h"

UI getChainLength(ULL number) {
    static const int cacheSize = 1 << 23;
    static UI cache[cacheSize], init = 0;
    if (init == 0) {
        memset(cache, 0, sizeof cache);
        cache[1] = 1;
        init = 1;
    }

    stack<ULL> memory;
    while (number >= cacheSize || !cache[number]) {
        memory.push(number);

        if (number % 2 == 0) {
            number /= 2;
        } else {
            number *= 3;
            number += 1;
        }
    }

    UI res = cache[number];
    while (!memory.empty()) {
        res++;
        UI top = memory.top();
        memory.pop();

        if (top < cacheSize) {
            cache[top] = res;
        }
    }

    return res;
}

UI solve014() {
    UI result, maxLen = 0;
    FORE(i,2,1000000) {
        UI len = getChainLength(i);
        //cout << "i = " << i << "; len = " << len << endl;
        if (len > maxLen) {
            maxLen = len;
            result = i;
        }
    }

    return result;
}

int main() {
    cout << solve014();
    return 0;
}
