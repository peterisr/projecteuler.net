/**
 * The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.
 *
 * How many n-digit positive integers exist which are also an nth power
 *
 * @task 063
 * @answer 49
 */
#include "../projecteuler.h"

UI solve063() {
    UI count = 0;

    FOR(base,1,9) {
        FOR(power,1,19) {
            ULL result = pow((ULL)base, (ULL)power);
            UI digitCount = getDigits(result, 10).size();
            if (digitCount == power) {
                //TRACE(base);
                //TRACE(power);
                //TRACE(digitCount);
                count++;
            }
        }
    }

    // base 9 satisfies the propertie for powers 1 .. 21
    // ( that was obtained by solving inequation 9^n < 10^(n-1) )
    count += 21;

    return count;
}

int main() {
    cout << solve063();
    return 0;
}
