/**
 * In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *
 *     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 *
 * It is possible to make £2 in the following way:
 *
 *     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 *
 * How many different ways can £2 be made using any number of coins?
 *
 * @task 031
 * @answer 73682
 */
#include "../projecteuler.h"

bool isGoodConfig(UI config) {
    UI sum = 0;

    // 1 pound (2 bits)
    sum += 100 * (config & (4 - 1));
    config >>= 2;

    // 50 pence (3 bits)
    sum += 50 * (config & (8 - 1));
    config >>= 3;

    // 20 pence (4 bits)
    sum += 20 * (config & (16 - 1));
    config >>= 4;

    // 10 pence (5 bits)
    sum += 10 * (config & (32 - 1));
    config >>= 5;

    // 5 pence (6 bits)
    sum += 5 * (config & (64 - 1));
    config >>= 6;

    // 2 pence (7 bits)
    sum += 2 * (config & (128 - 1));

    return (sum <= 200);
}

UI solve031() {
    UI result = 1; // 200p

    UI to = (1 << (7 + 6 + 5 + 4 + 3 + 2));
    for (UI config = 0; config < to; config++) {
        if (isGoodConfig(config)) {
            result++;
        }
    }

    return result;
}

int main() {
    cout << solve031();
    return 0;
}
