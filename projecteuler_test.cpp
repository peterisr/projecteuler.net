/**
 * Test my project euler functions.
 */
#include "projecteuler.h"

////////////////////////////////////////////////////////////////////
/// getPrimeFactors
///////////////////////////////////////////////////////////////////

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



////////////////////////////////////////////////////////////////////
/// primeTester
///////////////////////////////////////////////////////////////////

void testPrimeTester() {
    // Test small N
    primeTester *PT1 = new primeTester(1);
    assertFalse(PT1->isPrime(1), "PT N = 1, isPrime(1)");

    // Test average N
    primeTester *PT1000 = new primeTester(1000);
    assertFalse(PT1000->isPrime(1), "PT N = 1000, isPrime(1)");
    assertTrue(PT1000->isPrime(2), "PT N = 1000, isPrime(2)");
    assertTrue(PT1000->isPrime(3), "PT N = 1000, isPrime(3)");
    assertFalse(PT1000->isPrime(4), "PT N = 1000, isPrime(4)");
    assertTrue(PT1000->isPrime(5), "PT N = 1000, isPrime(5)");
    assertTrue(PT1000->isPrime(71), "PT N = 1000, isPrime(71)");
    assertTrue(PT1000->isPrime(977), "PT N = 1000, isPrime(977)");
    assertTrue(PT1000->isPrime(983), "PT N = 1000, isPrime(983)");
    assertFalse(PT1000->isPrime(1000), "PT N = 1000, isPrime(1000)");

    // Test prime N
    primeTester *PT91 = new primeTester(97);
    assertTrue(PT91->isPrime(97), "PT N = 97, isPrime(97)");

    // Test prime N is square
    primeTester *PT5041 = new primeTester(71 * 71);
    assertTrue(PT5041->isPrime(977), "PT N = 5041, isPrime(977)");
    assertTrue(PT5041->isPrime(983), "PT N = 5041, isPrime(983)");
    assertFalse(PT5041->isPrime(5041), "PT N = 5041, isPrime(5041)");
}


////////////////////////////////////////////////////////////////////
/// getPrimeList
///////////////////////////////////////////////////////////////////

void testGetPrimeList() {
    VUI list1 = getPrimeList(10);
    assertTrue(list1[0] == 2);
    assertTrue(list1[1] == 3);
    assertTrue(list1[2] == 5);
    assertTrue(list1[3] == 7);

    VUI list2 = getPrimeList(100);
    assertTrue(list2[4] == 11);
    assertTrue(list2[5] == 13);
    assertTrue(list2[6] == 17);
    assertTrue(list2[7] == 19);

    VUI list3 = getPrimeList(101);
    assertTrue(list3[list3.size() - 1] == 101);
}



////////////////////////////////////////////////////////////////////
/// isLeapYear
///////////////////////////////////////////////////////////////////

void testIsLeapYear() {
    assertTrue(isLeapYear(2012));
    assertTrue(isLeapYear(1996));
    assertTrue(isLeapYear(2000));
    assertFalse(isLeapYear(1999));
    assertFalse(isLeapYear(1900));
}


/**
 * Run all "code" tests.
 */
void suiteCode() {
    testGetPrimeFactors();
    testPrimeTester();
    testGetPrimeList();
    testIsLeapYear();
}

int main() {
    suiteCode();
    return 0;
}
