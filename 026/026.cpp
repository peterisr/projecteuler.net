/**
 * A unit fraction contains 1 in the numerator.
 * The decimal representation of the unit fractions with denominators 2 to 10 are given:
 *   1 / 2 = 0.5
 *   ...
 *   1 / 7 = 0.(142857)
 *   ...
 *   1 / 10 = 0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
 * It can be seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 *
 * @task 026
 * @answer 983
 */
#include "../projecteuler.h"

UI getPeriodLength(UI d) {
    UI top = 1;
    while (top < d) {
        top *= 10;
    }

    UI length = 0;
    set<UI> reminders;
    while (top != 0 && !INSET(reminders, top)) {
        top = top % d;
        if (top == 0 || INSET(reminders, top)) {
            continue;
        }

        reminders.insert(top);
        while (top < d) {
            top *= 10;
            length++;
        }
    }

    return (top == 0) ? 1 : length;
}

void e026() {
    UI maxPeriod = 0, best;
    for (UI d = 2; d < 1000; d++) {
        LD r = 1.0 / d;
        //cout << d << " => " << setprecision(18) << r << endl;
        cout << d << " => getPeriodLength() = " << getPeriodLength(d) << endl;
    }
}

UI solve026() {
    UI to = 1000;

    UI maxPeriodLen = 0, best;
    for (UI d = 2; d < to; d++) {
        UI periodLen = getPeriodLength(d);
        if (periodLen > maxPeriodLen) {
            best = d;
            maxPeriodLen = periodLen;
        }
    }

    return best;
}

int main() {
    //e026();
    cout << solve026();
    return 0;
}
