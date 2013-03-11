/**
 * If the numbers 1 to 5 are written out in words: one,
 * two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
 * how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two)
 * contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
 * The use of "and" when writing out numbers is in compliance with British usage.
 *
 * @task 017
 * @answer
 */
#include "../projecteuler.h"

UI oneTo9() {
    UI result = 0;

    result += strlen("one");
    result += strlen("two");
    result += strlen("three");
    result += strlen("four");
    result += strlen("five");
    result += strlen("six");
    result += strlen("seven");
    result += strlen("eight");
    result += strlen("nine");

    return result;
}

UI oneTo99() {
    UI result = 0, oTo9 = oneTo9();

    // 1..9
    result += oneTo9();

    // 10
    result += strlen("ten");

    // 11 .. 19
    result += strlen("eleven");
    result += strlen("twelve");
    result += strlen("thirteen");
    result += strlen("fourteen");
    result += strlen("fifteen");
    result += strlen("sixteen");
    result += strlen("seventeen");
    result += strlen("eighteen");
    result += strlen("nineteen");

    result += 8 * oTo9;

    // 20, 30, ..., 90
    result += 10 * strlen("twenty");
    result += 10 * strlen("thirty");
    result += 10 * strlen("forty");
    result += 10 * strlen("fifty");
    result += 10 * strlen("sixty");
    result += 10 * strlen("seventy");
    result += 10 * strlen("eighty");
    result += 10 * strlen("ninety");

    return result;
}

UI solve017() {
    UI oTo9 = oneTo9(), oTo99 = oneTo99(), solution = 0;

    // 1 .. 99
    solution += oTo99;

    // 101 .. 199, 201 .. 299, ...
    solution += 99 * oTo9;
    solution += 9 * 99 * (strlen("hundred") + strlen("and"));
    solution += 9 * oTo99;

    // 100, 200, ..., 900
    solution += oTo9;
    solution += 9 * strlen("hundred");

    // 1000
    solution += strlen("one") + strlen("thousand");

    return solution;
}

int main() {
    cout << solve017();
    return 0;
}
