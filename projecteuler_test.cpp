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



////////////////////////////////////////////////////////////////////
/// getDaysInMonth
///////////////////////////////////////////////////////////////////

void testGetDaysInMonth() {
    assertTrue(getDaysInMonth(2013, 2) == 28);
    assertTrue(getDaysInMonth(2013, 3) == 31);
    assertTrue(getDaysInMonth(2013, 4) == 30);
    assertTrue(getDaysInMonth(2013, 12) == 31);
    assertTrue(getDaysInMonth(2000, 2) == 29);
    assertTrue(getDaysInMonth(1999, 2) == 28);
    assertTrue(getDaysInMonth(1996, 2) == 29);
}



////////////////////////////////////////////////////////////////////
/// getAllDistinctDivisors
///////////////////////////////////////////////////////////////////

void testGetAllDistinctDivisors() {
    assertEquals(getAllDistinctDivisors(1), {1});
    assertEquals(getAllDistinctDivisors(2), {1, 2});
    assertEquals(getAllDistinctDivisors(3), {1, 3});
    assertEquals(getAllDistinctDivisors(4), {1, 2, 4});
    assertEquals(getAllDistinctDivisors(32), {1, 2, 4, 8, 16, 32});
    assertEquals(getAllDistinctDivisors(40), {1, 2, 4, 5, 8, 10, 20, 40});
}



////////////////////////////////////////////////////////////////////
/// moveToNextPermutation
///////////////////////////////////////////////////////////////////

void assertMoveToNextPermutation(string input, string expect) {
    moveToNextPermutation(input);
    if (input != expect) {
        cout << "assertMoveToNextPermutation :: expect '" << expect << "'; got '" << input << "'" << endl;
    }
}

void testMoveToNextPermutation() {
    // 1
    assertMoveToNextPermutation("1", "1");

    // 1, 2
    assertMoveToNextPermutation("12", "21");

    // 1, 2, 3
    assertMoveToNextPermutation("123", "132");
    assertMoveToNextPermutation("132", "213");
    assertMoveToNextPermutation("213", "231");
    assertMoveToNextPermutation("231", "312");
    assertMoveToNextPermutation("312", "321");
    assertMoveToNextPermutation("321", "321");

    // random
    assertMoveToNextPermutation("0987654312", "0987654321");
    assertMoveToNextPermutation("0987654321", "1023456789");
    assertMoveToNextPermutation("05321", "10235");
    assertMoveToNextPermutation("15320", "20135");

    // letters
    assertMoveToNextPermutation("ABCD", "ABDC");
    assertMoveToNextPermutation("DCAB", "DCBA");

    // check last permutation
    string test("321");
    assertFalse(moveToNextPermutation(test));
}



////////////////////////////////////////////////////////////////////
/// pow
///////////////////////////////////////////////////////////////////

void testPow() {
    assertTrue(pow(0, 0) == 1);
    assertTrue(pow(0, 1) == 0);
    assertTrue(pow(0, 10) == 0);

    assertTrue(pow(1, 0) == 1);
    assertTrue(pow(2, 0) == 1);
    assertTrue(pow(1000, 0) == 1);

    assertTrue(pow(1, 1) == 1);
    assertTrue(pow(5, 1) == 5);
    assertTrue(pow(1010, 1) == 1010);

    assertTrue(pow(1, 2) == 1);
    assertTrue(pow(5, 2) == 5*5);
    assertTrue(pow(1010, 2) == 1010*1010);

    assertTrue(pow(1, 10000) == 1);
    assertTrue(pow(2, 10) == 1024);
    assertTrue(pow(2, 13) == 8192);

    ULL res = (1ull << 63);
    assertTrue(pow(2ull, 63ull) == res);
}



////////////////////////////////////////////////////////////////////
/// sumOfDigitPowers
///////////////////////////////////////////////////////////////////

void testSumOfDigitPowers() {
    assertTrue(sumOfDigitPowers(0, 0) == 0);
    assertTrue(sumOfDigitPowers(0, 1) == 0);
    assertTrue(sumOfDigitPowers(0, 10) == 0);
    assertTrue(sumOfDigitPowers(10, 0) == 2);
    assertTrue(sumOfDigitPowers(5000, 0) == 4);

    assertTrue(sumOfDigitPowers(1, 2) == 1);
    assertTrue(sumOfDigitPowers(2, 2) == 4);
    assertTrue(sumOfDigitPowers(22, 2) == 8);
    assertTrue(sumOfDigitPowers(222, 2) == 12);
    assertTrue(sumOfDigitPowers(2222, 2) == 16);
    assertTrue(sumOfDigitPowers(25, 3) == 133);
}



////////////////////////////////////////////////////////////////////
/// getDigitCount
///////////////////////////////////////////////////////////////////

void testGetDigitCount() {
    assertTrue(getDigitCount(0) == 1);
    assertTrue(getDigitCount(1) == 1);
    assertTrue(getDigitCount(10) == 2);
    assertTrue(getDigitCount(45) == 2);
    assertTrue(getDigitCount(1000) == 4);
    assertTrue(getDigitCount(1234567890ull) == 10);
}



////////////////////////////////////////////////////////////////////
/// getDigitMask
///////////////////////////////////////////////////////////////////

void testGetDigitMask() {
    assertTrue(getDigitMask(0) == 1);
    assertTrue(getDigitMask(1) == 2);
    assertTrue(getDigitMask(2) == 4);
    assertTrue(getDigitMask(3) == 8);
    assertTrue(getDigitMask(4) == 16);
    assertTrue(getDigitMask(9) == 512);

    assertTrue(getDigitMask(9999) == 512);
    assertTrue(getDigitMask(1111) == 2);
    assertTrue(getDigitMask(1230) == 15);
    assertTrue(getDigitMask(230) == 13);
    assertTrue(getDigitMask(1234567890ull) == 1023);
}



////////////////////////////////////////////////////////////////////
/// getGCD
///////////////////////////////////////////////////////////////////

void testGetGCD() {
    assertTrue(getGCD(1, 1) == 1);
    assertTrue(getGCD(2, 2) == 2);
    assertTrue(getGCD(3, 2) == 1);
    assertTrue(getGCD(2, 3) == 1);
    assertTrue(getGCD(16, 4) == 4);

    assertTrue(getGCD(128, 32) == 32);
    assertTrue(getGCD(7*5*3, 11*7*3) == 7*3);
    assertTrue(getGCD((1ull << 62), 111111111111ull) == 1);
}



/**
 * Run all "code" tests.
 */
void suiteCode() {
    testGetPrimeFactors();
    testPrimeTester();
    testGetPrimeList();
    testIsLeapYear();
    testGetDaysInMonth();
    testGetAllDistinctDivisors();
    testMoveToNextPermutation();
    testPow();
    testSumOfDigitPowers();
    testGetDigitCount();
    testGetDigitMask();
    testGetGCD();
}

int main() {
    suiteCode();
    return 0;
}
