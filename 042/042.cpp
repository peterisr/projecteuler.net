/**
 * The nth term of the sequence of triangle numbers is given by, tn = (1/2)*n(n+1); so the first ten triangle numbers are:
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
 * For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt, a 16K text file containing nearly two-thousand common English words, how many are triangle words?
 *
 * @task 042
 * @answer 162
 */
#include "../projecteuler.h"

bool isTriangleNumber(UI number) {
    number *= 2;

    LD s = sqrt(number + 0.0);
    UI sqrtUI = (UI)s;

    return (
        sqrtUI * (sqrtUI + 1) == number
        || (sqrtUI + 1) * (sqrtUI + 2) == number
    );
}

UI getWordValue(const string &word) {
    UI value = 0;
    F(i,word.size()) {
        value += (word[i] - 'A') + 1;
    }

    return value;
}

UI solve042() {
    UI result = 0;

    fstream in("words.txt");
    string line;
    in >> line;

    vector<string> words = parseWordList(line);
    F(i,words.size()) {
        UI value = getWordValue(words[i]);
        if (isTriangleNumber(value)) {
            //TRACE(words[i]);
            //TRACE(value);
            result++;
        }
    }

    return result;
}

int main() {
    cout << solve042();
    return 0;
}
