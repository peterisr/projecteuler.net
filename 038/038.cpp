/**
 * Take the number 192 and multiply it by each of 1, 2, and 3:
 *
 *     192 x 1 = 192
 *     192 x 2 = 384
 *     192 x 3 = 576
 *
 * By concatenating each product we get the 1 to 9 pandigital, 192384576.
 * We will call 192384576 the concatenated product of 192 and (1,2,3).
 *
 * The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5,
 * giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).
 *
 * What is the largest 1 to 9 pandigital 9-digit number that can be formed as the
 * concatenated product of an integer with (1,2, ... , n) where n > 1?
 *
 * @task 038
 * @answer 932718654
 */
#include "../projecteuler.h"

bool isPandigital(ULL number) {
    return (getDigitCount(number) == 9 && getDigitMask(number) == ((1 << 10) - 2));
}

ULL solve038() {
    ULL result = 0;

    FOR(n,2,10) {
        UI number = 1;
        ULL current;
        do {
            current = number;
            FOR(i,2,n + 1) {
                FOR (j,0,getDigitCount(number * i)) {
                    current *= 10;
                }
                current += number * i;
            }

            if (isPandigital(current)) {
                //TRACE(n);
                //TRACE(number);
                //TRACE(current);
                result = MAX(result, current);
            }

            number++;
        } while (getDigitCount(current) < 10);
    }

    return result;
}

int main() {
    cout << solve038();
    return 0;
}
