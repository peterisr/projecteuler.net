/**
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 *
 * @task 016
 * @answer 1366
 */
#include "../projecteuler.h"

UI solve016() {
    const UI power = 1000;

    UI R[power / 3 + 1];
    memset(R, 0, sizeof R);

    R[0] = 1;
    UI maxNum = 0;
    F(i,power) {
        UI rem = 0;
        F(j, maxNum + 1) {
            R[j] = R[j] * 2 + rem;
            rem = R[j] / 10;
            R[j] %= 10;
        }
        R[maxNum + 1] = rem;

        if (R[maxNum + 1] > 0) {
            maxNum++;
        }

        if (false) {
            cout << "2^" << (i + 1) << ": ";
            for (int i = maxNum; i >= 0; i--) {
                cout << R[i];
            }
            cout << endl;
        }
    }

    //cout << "# of digits in 2^" << power << ": " << (maxNum + 1) << endl;

    UI sum = 0;
    F(j,maxNum + 1) {
        sum += R[j];
    }

    return sum;
}

int main() {
    cout << solve016();
    return 0;
}
