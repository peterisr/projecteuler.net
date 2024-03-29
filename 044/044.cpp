/**
 * Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2.
 * The first ten pentagonal numbers are:
 *
 * 1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...
 *
 * It can be seen that P4 + P7 = 22 + 70 = 92 = P8.
 * However, their difference, 70 − 22 = 48, is not pentagonal.
 *
 * Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal
 * and D = |Pk − Pj| is minimised; what is the value of D?
 *
 * @task 044
 * @answer 5482660
 */
#include "../projecteuler.h"

UI solve044() {
    const UI assumption = (UI)1e7;

    static bool isPent[assumption];
    memset(isPent, 0, sizeof isPent);

    static UI pent = 1, n = 1, pents[assumption / 100 + 10], pc = 0;
    do {
        isPent[pent] = true;
        pents[pc++] = pent;
        pent += 3*n++ + 1;
    } while (pent < assumption);

    UI minD = (UI)1e9;
    FOR(i,0,pc) {
        FOR(j,i+1,pc) {
            UI s = pents[j] + pents[i], d = pents[j] - pents[i];
            if (
                isPent[d]
                && s < assumption
                && isPent[s]
            ) {
                //TRACE(i);
                //TRACE(j);
                minD = MIN(minD, d);
            }
        }
    }

    return minD;
}

int main() {
    cout << solve044();
    return 0;
}
