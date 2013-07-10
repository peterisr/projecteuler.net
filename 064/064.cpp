/**
 * All square roots are periodic when written as continued fractions and can be written in the form:
 *
 * For example, let us consider √23:
 *
 * If we continue we would get the following expansion:
 *
 * The process can be summarised as follows:
 *
 * It can be seen that the sequence is repeating.
 * For conciseness, we use the notation √23 = [4;(1,3,1,8)], to indicate that the block (1,3,1,8) repeats indefinitely.
 *
 * The first ten continued fraction representations of (irrational) square roots are:
 *
 * √2=[1;(2)], period=1
 * √3=[1;(1,2)], period=2
 * √5=[2;(4)], period=1
 * √6=[2;(2,4)], period=2
 * √7=[2;(1,1,1,4)], period=4
 * √8=[2;(1,4)], period=2
 * √10=[3;(6)], period=1
 * √11=[3;(3,6)], period=2
 * √12= [3;(2,6)], period=2
 * √13=[3;(1,1,1,1,6)], period=5
 *
 * Exactly four continued fractions, for N ≤ 13, have an odd period.
 * How many continued fractions for N ≤ 10000 have an odd period?
 *
 * @task 064
 * @answer
 */
#include "../projecteuler.h"

#define BITS 20
#define TUPLE(a, b, c) ((((ULL)a) << 40) | (((ULL)b) << 20) | ((ULL)c))
#define debug 0

UI lbSqrt(UI x) {
    UI r = 0;
    int t = 15;

    while (t >= 0) {
        UI test = r + (1 << t);

        if (test*test <= x) {
            r = test;
        }

        t--;
    }

    return r;
}

UI getPeriodLength(UI n) {
    UI a, b, oldB, c, x, lb, cnt;
    ULL t;

    cnt = 0;
    lb = lbSqrt(n);
    c = a = lb;
    b = 1;
    t = TUPLE(a, b, c);

    set<ULL> seen;
    if (debug) {
        TRACE(n);
    }
    while (!INSET(seen, t)) {
        seen.insert(t);

        if (debug) {
            TRACE(a);
            TRACE(b);
            TRACE(c);
            TRACE("---------------");
        }

        if (a >= (1 << BITS) || b >= (1 << BITS) || c >= (1 << BITS)) {
            TRACE("FAK!");
        }

        oldB = b;
        a = (oldB * (lb + c)) / (n - c * c);
        b = (n - c * c) / oldB;
        c = ( (n - c * c) * a - c * oldB ) / oldB;

        t = TUPLE(a, b, c);
        cnt++;
    }

    cnt--;

    if (debug) {
        TRACE(cnt);
        TRACE("<<<<<<<<<<<<>>>>>>>>>>>");
    }

    return cnt;
}

UI solve064() {
    UI oddPeriods = 0, s = 2;
    const UI from = 2, to = 10000;

    FOR(i,from,to + 1) {
        // Skip perfect squares
        if (s*s == i) {
            s++;
            continue;
        }

        // Count # of odd periods
        UI periodLength = getPeriodLength(i);
        if (periodLength % 2) {
            oddPeriods++;
        }
    }

    return oddPeriods;
}

int main() {
    cout << solve064();
    return 0;
}
