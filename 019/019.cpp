/**
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 *     1 Jan 1900 was a Monday.
 *     Thirty days has September,
 *     April, June and November.
 *     All the rest have thirty-one,
 *     Saving February alone,
 *     Which has twenty-eight, rain or shine.
 *     And on leap years, twenty-nine.
 *     A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 *
 * @task 019
 * @answer 171
 */
#include "../projecteuler.h"

UI solve019() {
    UI d = 1, m = 1, y = 1901, n = 2, result = 0;
    while (y <= 2000) {
        if (n == 7 && d == 1) {
            result++;
        }

        //cout << y << "-" << m << "-" << d << " is " << n << endl;

        d++;
        if (d > getDaysInMonth(y, m)) {
            m++;
            d = 1;
            if (m > 12) {
                y++;
                m = 1;
            }
        }

        n++;
        if (n > 7) {
            n = 1;
        }
    }

    return result;
}

int main() {
    cout << solve019();
    return 0;
}
