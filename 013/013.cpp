/**
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 *     see: 013_numbers.txt
 *
 * @task 013
 * @answer 5537376230
 */
#include "../projecteuler.h"

ULL solve013() {
    ifstream in("013_numbers.txt");
    string number;
    vector<string> numbers;
    F(i,100) {
        in >> number;
        numbers.push_back(number);
        //cout << number << endl;
    }

    UI digitCounts[61];
    memset(digitCounts, 0, sizeof digitCounts);
    F(i,100) {
        F(j,numbers[i].size()) {
            digitCounts[5 + j] += numbers[i][j] - '0';
        }
    }

    for (UI i = 60; i >= 1; i--) {
        digitCounts[i - 1] += digitCounts[i] / 10;
        digitCounts[i] %= 10;
    }

    UI i = 0;
    while (digitCounts[i] == 0) {
        i++;
    }

    ULL res = 0;
    for (UI j = i; j < i + 10; j++) {
        res *= 10;
        res += digitCounts[j];
    }

    return res;
}

int main() {
    cout << solve013();
    return 0;
}
