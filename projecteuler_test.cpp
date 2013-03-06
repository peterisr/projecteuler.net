/**
 * Test my project euler functions.
 */
#include "projecteuler.h"

template <class T>
void assertGetPrimeFactors(T input, initializer_list< initializer_list<T> > expect) {
    vector< pair<T, UI> > result = getPrimeFactors(input);
    set<T> unique;
    map<T, UI> mapping;

    T check = 1;
    FOREACH (e, result) {
        if (INSET(unique, e->first)) {
            cout << "assertGetPrimeFactors :: " << input << " :: factor " << e->first << " encountered more than once.";
            return;
        }

        mapping[e->first] = e->second;
        check *= pow(e->first, e->second);
    }

    if (check != input) {
        cout << "assertGetPrimeFactors :: " << input << " :: product of factors does not equal input. Got " << check << "." << endl;
        return;
    }

    FOREACH(iter, expect) {
        auto i = iter->begin();
        T factor = *i;
        i++;
        UI count = *i;

        if (!INMAP(mapping, factor) || mapping[factor] != count) {
            cout << "assertGetPrimeFactors :: " << input << " :: problem with expected factor " << factor << "^" << count << ". Got: ";
            FOREACH (it, result) {
                cout << it->first << "^" << it->second << ", ";
            }
            cout << endl;
            return;
        }
    }
}

void testGetPrimeFactors() {
    assertGetPrimeFactors(1, {});
    assertGetPrimeFactors(2, {{2,1}});
    assertGetPrimeFactors(3, {{3,1}});
    assertGetPrimeFactors(4, {{2,2}});
    assertGetPrimeFactors(5, {{5,1}});
    assertGetPrimeFactors(9, {{3,2}});
    assertGetPrimeFactors(27, {{3,3}});
    assertGetPrimeFactors(24, {{2,3},{3,1}});
    assertGetPrimeFactors(81, {{3,4}});
    assertGetPrimeFactors(243, {{3,5}});
    assertGetPrimeFactors(3*5*7, {{3,1}, {5,1}, {7,1}});
    assertGetPrimeFactors(8*3*5, {{2,3}, {3,1}, {5,1}});
    assertGetPrimeFactors(1024, {{2,10}});

    // ULL test
    ULL num1 = (1ull << 55);
    assertGetPrimeFactors(num1, {{(ULL)2,(ULL)55}});
}

/**
 * Run all "code" tests.
 */
void suiteCode() {
    testGetPrimeFactors();
}

int main() {
    suiteCode();
    return 0;
}
