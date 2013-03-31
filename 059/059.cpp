/**
 * Each character on a computer is assigned a unique code and the preferred standard is
 * ASCII (American Standard Code for Information Interchange).
 * For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *
 * A modern encryption method is to take a text file, convert the bytes to ASCII,
 * then XOR each byte with a given value, taken from a secret key.
 * The advantage with the XOR function is that using the same encryption key on the cipher text,
 * restores the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65.
 *
 * For unbreakable encryption, the key is the same length as the plain text message,
 * and the key is made up of random bytes. The user would keep the encrypted message
 * and the encryption key in different locations, and without both "halves",
 * it is impossible to decrypt the message.
 *
 * Unfortunately, this method is impractical for most users, so the modified method
 * is to use a password as a key. If the password is shorter than the message, which
 * is likely, the key is repeated cyclically throughout the message. The balance for
 * this method is using a sufficiently long password key for security, but short
 * enough to be memorable.
 *
 * Your task has been made easy, as the encryption key consists of three lower case characters.
 * Using cipher1.txt (right click and 'Save Link/Target As...'), a file containing the
 * encrypted ASCII codes, and the knowledge that the plain text must contain common English words,
 * decrypt the message and find the sum of the ASCII values in the original text.
 *
 * @task 059
 * @answer 107359
 */
#include "../projecteuler.h"

VUI xorDecode(const VUI &codes, const VUI &key) {
    VUI result;
    result.resize(codes.size());
    UI k = 0;

    F(i,codes.size()) {
        result[i] = (codes[i] ^ key[k]);
        k = (k + 1) % key.size();
    }

    return result;
}

UI getDecodedScore(const VUI &text) {
    UI score = 0;

    F(i,text.size()) {
        if (
            text[i] >= 'a' && text[i] <= 'z'
            || text[i] >= 'A' && text[i] <= 'Z'
            || text[i] >= '0' && text[i] <= '9'
            || text[i] == ' '
            || text[i] == '.'
            || text[i] == ','
            || text[i] == '!'
            || text[i] == '?'
        ) {
            score++;
        }
    }

    return score;
}

void printText(const VUI &text) {
    cout << "printText: ";
    F(i,text.size()) {
        cout << ((char)text[i]);
    }
    cout << endl;
}

UI solve059() {

    ifstream in("cipher1.txt");
    UI asciiCode;
    VUI codes;
    while (in >> asciiCode) {
        codes.push_back(asciiCode);
    }

    UI maxScore = 0;
    VUI key, bestText;
    key.resize(3);
    FOR(a,'a','z' + 1) {
        FOR(b,'a','z' + 1) {
            FOR(c,'a','z' + 1) {
                key[0] = a;
                key[1] = b;
                key[2] = c;
                VUI decoded = xorDecode(codes, key);
                UI score = getDecodedScore(decoded);
                if (score > maxScore) {
                    bestText = decoded;
                    maxScore = score;
                }
            }
        }
    }

    //printText(bestText);

    UI asciiSum = 0;
    F(i,bestText.size()) {
        asciiSum += bestText[i];
    }

    return asciiSum;
}

int main() {
    cout << solve059();
    return 0;
}
