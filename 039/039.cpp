/**
 * If p is the perimeter of a right angle triangle with integral length sides,
 * {a,b,c}, there are exactly three solutions for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p <= 1000, is the number of solutions maximised?
 *
 * @task 039
 * @answer 840
 */
#include "../projecteuler.h"

UI solve039() {
    const UI to = 1000;

    UI solutionCount[to + 1];
    memset(solutionCount, 0, sizeof(solutionCount));

    UI a = 0, b = 0, c = 0;
    while (a++ < to) {
        while (a + b++ < to) {
            while (a + b + c++ < to) {
                if (a*a + b*b == c*c && a <= b) {
                    solutionCount[a + b + c]++;
                    /*
                    TRACE(a);
                    TRACE(b);
                    TRACE(c);
                    TRACE(a + b + c);
                    */
                }
            }

            c = 0;
        }

        b = 0;
    }

    UI p = 0;
    F(i,to + 1) {
        if (solutionCount[p] < solutionCount[i]) {
            p = i;
        }
    }

    return p;
}

int main() {
    cout << solve039();
    return 0;
}
