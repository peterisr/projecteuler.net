/**
 * The cube, 41063625 (3453), can be permuted to produce two other cubes:
 * 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube
 * which has exactly three permutations of its digits which are also cube.
 *
 * Find the smallest cube for which exactly five permutations of its digits are cube.
 *
 * @task 062
 * @answer 127035954683
 */
#include "../projecteuler.h"

ULL extendedDigitMask(ULL number) {
    UC digitCounts[10];
    memset(digitCounts, 0, 10);

    while (number > 0) {
        digitCounts[number % 10]++;
        number /= 10;
    }

    ULL mask = 0;
    F(i,10) {
        mask |= (((ULL)digitCounts[i]) << (i * 5));
    }

    return mask;
}

bool isCube(ULL number) {
    return false;
}

ULL getCube(ULL base) {
    ULL c = base;
    c *= base;
    c *= base;
    return c;
}

bool hasBiggerCubePermutations(ULL number, ULL lagestCheck) {
    UI numberCount = getDigits(number, 10).size();
    return 0;
}

ULL solve062() {
    map<ULL, UI> count;
    map<ULL, ULL> smallest;
    vector<ULL> fiveOrMore;
    ULL tp = 10, base = 1;
    while (1) {
        ULL cube = getCube(base++);
        ULL mask = extendedDigitMask(cube);

        if (tp < cube) {
            bool gotAny = false;
            ULL result = (ULL)(1e18);
            F(i,fiveOrMore.size()) {
                if (count[fiveOrMore[i]] == 5) {
                    gotAny = true;
                    result = MIN(result, smallest[fiveOrMore[i]]);
                }
            }
            if (gotAny) {
                return result;
            }
            fiveOrMore.clear();
            count.clear();
            smallest.clear();
        }

        while (tp < cube) {
            tp *= 10;
        }

        if (INMAP(count, mask)) {
            count[mask]++;
            if (count[mask] == 5) {
                fiveOrMore.push_back(mask);
            }
        } else {
            count[mask] = 1;
            smallest[mask] = cube;
        }
    }

    return 0;
}

int main() {
    cout << solve062();
    return 0;
}
