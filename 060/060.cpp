/**
 * The primes 3, 7, 109, and 673, are quite remarkable.
 * By taking any two primes and concatenating them in any order the result will always be prime.
 * For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792,
 * represents the lowest sum for a set of four primes with this property.
 *
 * Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
 *
 * @task 060
 * @answer 26033
 */
#include "../projecteuler.h"

UI getMinSum(const VUI &primes, const set<UI> *friendly, UI size) {
    UI minSum = (UI)1e9;
    FOR(i,0,primes.size()) {
        UI a = primes[i];

        if (a >= minSum) {
            break;
        }

        FOREACH(iterB, friendly[a]) {
            UI b = *iterB;

            if (a + b >= minSum || b >= a) {
                break;
            }

            FOREACH(iterC, friendly[b]) {
                UI c = *iterC;

                if (a + b + c >= minSum || c >= b) {
                    break;
                }

                if (
                    c == a
                    || !INSET(friendly[a], c)
                ) {
                    continue;
                }

                FOREACH(iterD, friendly[c]) {
                    UI d = *iterD;

                    if (a + b + c + d >= minSum || d >= c) {
                        break;
                    }

                    if (
                        d == a
                        || d == b
                        || !INSET(friendly[a], d)
                        || !INSET(friendly[b], d)
                    ) {
                        continue;
                    }

                    FOREACH(iterE, friendly[d]) {
                        UI e = *iterE;

                        if (a + b + c + d + e >= minSum || e >= d) {
                            break;
                        }

                        if (
                            e == a
                            || e == b
                            || e == c
                            || !INSET(friendly[a], e)
                            || !INSET(friendly[b], e)
                            || !INSET(friendly[c], e)
                        ) {
                            continue;
                        }

                        if (false) {
                            TRACE(a);
                            TRACE(b);
                            TRACE(c);
                            TRACE(d);
                            TRACE(e);
                        }

                        UI sum = a + b + c + d + e;
                        minSum = MIN(sum, minSum);
                    }
                }
            }
        }
    }

    return minSum;
}

UI solve060() {
    const UI maxSplit = (UI)1e8;
    const UI friendlySize = (maxSplit / 10) + 10;
    static VUI primes = getPrimeList(maxSplit);
    static primeTester PT(maxSplit);
    static set<UI> friendly[friendlySize];

    //cout << "Starting solution" << endl;

    UI i = 0;
    while (primes[i + 1] < 10) {
        i++;
    }

    UI primeTP = 100;
    for (; i < primes.size(); i++) {
        if (primes[i] > primeTP) {
            primeTP *= 10;
        }

        for (UI tp = 10; tp < primeTP; tp *= 10) {
            UI p1 = primes[i] / tp;
            UI p2 = primes[i] % tp;
            if (
                p1 > p2
                || !PT.isPrime(p1)
                || !PT.isPrime(p2)
                || p2 < (tp / 10)
            ) {
                continue;
            }

            UI check = p2 * (primeTP / tp) + p1;
            if (PT.isPrime(check)) {
                friendly[p1].insert(p2);
                friendly[p2].insert(p1);
            }
        }
    }

    //cout << "Generated all friendly." << endl;

    if (false) {
        F(i,friendlySize) {
            if (friendly[i].size() > 10) {
                TRACE(i);
            }
        }
    }

    UI result = getMinSum(primes, friendly, friendlySize);
    //cout << "Got result." << endl;
    return result;
}

int main() {
    cout << solve060();
    return 0;
}
