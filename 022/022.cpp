/**
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand
 * first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
 * is the 938th name in the list.
 * So, COLIN would obtain a score of 938 × 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 *
 * @task 022
 * @answer 871198282
 */
#include "../projecteuler.h"

vector<string> getSortedWordList(string raw) {
    vector<string> result = parseWordList(raw);
    sort(result.begin(), result.end());
    return result;
}

inline UI getWordScore(const string &str) {
    UI score = 0;
    F(i,str.size()) {
        score += str[i] - 'A' + 1;
    }

    return score;
}

ULL calculateScore(const vector<string> &wordList) {
    ULL score = 0;
    F(i,wordList.size()) {
        UI wordScore = getWordScore(wordList[i]);
        score += (i + 1) * wordScore;
        if (i == 937) {
            TRACE(wordList[i]);
            TRACE(wordScore);
        }
    }
    return score;
}

ULL solve022() {
    string line;

    ifstream in("input022.txt");
    in >> line;
    in.close();

    ULL score = calculateScore(getSortedWordList(line));
    return score;
}

int main() {
    cout << solve022();
    return 0;
}
