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

void assertMoveToNextPermutationString(string input, string expect) {
    moveToNextPermutation(input);
    if (input != expect) {
        cout << "assertMoveToNextPermutationString :: expect '" << expect << "'; got '" << input << "'" << endl;
    }
}

void assertMoveToNextPermutationVector(initializer_list<UI> input, initializer_list<UI> expect) {
    vector<UI> inputV;
    inputV.resize(input.size());
    copy(input.begin(), input.end(), inputV.begin());

    moveToNextPermutation(inputV);

    vector<UI> expectV;
    expectV.resize(expect.size());
    copy(expect.begin(), expect.end(), expectV.begin());

    F(i,inputV.size()) {
        if (inputV[i] != expectV[i]) {
            cout << "assertMoveToNextPermutationVector :: expect";
            TRACE1D(expectV, expectV.size());
            TRACE1D(inputV, inputV.size());
            cout << endl;
            return;
        }
    }
}

void testMoveToNextPermutation() {
    // 1
    assertMoveToNextPermutationString("1", "1");

    // 1, 2
    assertMoveToNextPermutationString("12", "21");

    // 1, 2, 3
    assertMoveToNextPermutationString("123", "132");
    assertMoveToNextPermutationString("132", "213");
    assertMoveToNextPermutationString("213", "231");
    assertMoveToNextPermutationString("231", "312");
    assertMoveToNextPermutationString("312", "321");
    assertMoveToNextPermutationString("321", "321");

    // random
    assertMoveToNextPermutationString("0987654312", "0987654321");
    assertMoveToNextPermutationString("0987654321", "1023456789");
    assertMoveToNextPermutationString("05321", "10235");
    assertMoveToNextPermutationString("15320", "20135");

    // letters
    assertMoveToNextPermutationString("ABCD", "ABDC");
    assertMoveToNextPermutationString("DCAB", "DCBA");

    // check last permutation
    string test("321");
    assertFalse(moveToNextPermutation(test));


    // vectors
    assertMoveToNextPermutationVector({1,2}, {2,1});
    assertMoveToNextPermutationVector({1,2,3,4}, {1,2,4,3});
    assertMoveToNextPermutationVector({1,2,4,3}, {1,3,2,4});


    // Test permutations with equal elements
    assertMoveToNextPermutationVector({1,1,1,2}, {1,1,2,1});
    assertMoveToNextPermutationVector({1,1,2,1}, {1,2,1,1});
    assertMoveToNextPermutationVector({1,2,1,1}, {2,1,1,1});
    assertMoveToNextPermutationVector({2,1,1,1}, {2,1,1,1});
    vector<UI> testV;
    testV.push_back(2);
    testV.push_back(1);
    testV.push_back(1);
    assertFalse(moveToNextPermutation(testV));
}



////////////////////////////////////////////////////////////////////
/// pow
///////////////////////////////////////////////////////////////////

void testPow() {
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
/// pow with mod
///////////////////////////////////////////////////////////////////

void testPowWithMod() {
    assertTrue(powWithMod(0, 1, 10) == 0);
    assertTrue(powWithMod(0, 10, 10) == 0);

    assertTrue(powWithMod(10, 10, 10) == 0);
    assertTrue(powWithMod(100, 100, 10) == 0);
    assertTrue(powWithMod(2, 10, 10) == 4);

    assertTrue(powWithMod(3, 4, 10) == 1);
    assertTrue(powWithMod(2, 1000, 10) == 6);
    assertTrue(powWithMod(1000, 1000, 2) == 0);
    assertTrue(powWithMod(1000, 1000, 5) == 0);
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



////////////////////////////////////////////////////////////////////
/// isPalindome
///////////////////////////////////////////////////////////////////

void testIsPalindome() {
    assertTrue(isPalindome(1, 10));
    assertTrue(isPalindome(33, 10));
    assertTrue(isPalindome(101, 10));
    assertTrue(isPalindome(1001, 10));
    assertTrue(isPalindome(10101, 10));
    assertTrue(isPalindome(50405, 10));

    assertFalse(isPalindome(512415, 10));
    assertFalse(isPalindome(45, 10));
    assertFalse(isPalindome(54, 10));
    assertFalse(isPalindome(9887, 10));
    assertFalse(isPalindome(1000101, 10));

    assertTrue(isPalindome(585, 2));
    assertTrue(isPalindome(3, 2));
    assertTrue(isPalindome(5, 2));
    assertTrue(isPalindome(9, 2));
}



////////////////////////////////////////////////////////////////////
/// getDigits
///////////////////////////////////////////////////////////////////

void testGetDigits() {
    // base 10 tests
    assertEquals(getDigits(0, 10), {0});
    assertEquals(getDigits(7, 10), {7});
    assertEquals(getDigits(7654, 10), {7,6,5,4});
    assertEquals(
        getDigits(1234567891000ull, 10),
        {1,2,3,4,5,6,7,8,9,1,0,0,0}
    );

    // base 2 tests
    assertEquals(getDigits(0, 2), {0});
    assertEquals(getDigits(1, 2), {1});
    assertEquals(getDigits(2, 2), {1,0});
    assertEquals(getDigits(3, 2), {1,1});
    assertEquals(getDigits(5, 2), {1,0,1});

    // base 8 tests
    assertEquals(getDigits(0777, 8), {7,7,7});
    assertEquals(getDigits(0102, 8), {1,0,2});
}

////////////////////////////////////////////////////////////////////
/// stringTo
///////////////////////////////////////////////////////////////////

void testStringTo() {
    string lolz = "";
    ULL a = stringTo(lolz);
    assertTrue(stringTo("") == 0);
    assertTrue(stringTo("0") == 0);
    assertTrue(stringTo("1") == 1);
    assertTrue(stringTo("+1") == 1);
    assertTrue(stringTo("-1") == -1);
    assertTrue(stringTo("987") == 987);
    assertTrue(stringTo("+987") == +987);
    assertTrue(stringTo("-987") == -987);
    assertTrue(stringTo("1234567890") == 1234567890ull);
    assertTrue(stringTo("123456789") == 123456789);
    assertTrue(stringTo("987654321") == 987654321);
}



////////////////////////////////////////////////////////////////////
/// isPrime
///////////////////////////////////////////////////////////////////

void testIsPrime() {
    assertFalse(isPrime(0));
    assertFalse(isPrime(1));
    assertTrue(isPrime(2));
    assertTrue(isPrime(3));
    assertFalse(isPrime(4));
    assertTrue(isPrime(5));
    assertTrue(isPrime(101));
    assertFalse(isPrime(101 * 29));
    assertFalse(isPrime(1ull << 63));
    assertFalse(isPrime(987654321));
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
    testPowWithMod();
    testSumOfDigitPowers();
    testGetDigitCount();
    testGetDigitMask();
    testGetGCD();
    testIsPalindome();
    testGetDigits();
    testStringTo();
    testIsPrime();
}

int main() {
    suiteCode();
    return 0;
}
