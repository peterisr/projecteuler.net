#ifndef PROJECTEULER_TESTING
#define PROJECTEULER_TESTING 1

#include "projecteuler.h"
#include <exception>

void assertTrue(bool expression, const char *msg = NULL) {
    if (!expression) {
        if (msg != NULL) {
            cout << "assertTrue :: Error :: " <<  msg << endl;
        } else {
            throw new exception();
        }
    }
}

void assertFalse(bool expression, const char *msg = NULL) {
    if (expression) {
        if (msg != NULL) {
            cout << "assertFalse :: Error :: " << msg << endl;
        } else {
            throw new exception();
        }
    }
}

// Compare two vectors (or initializer_lists)
template <class M, class N>
void assertEquals(const M &a, const N &b, const char *msg = NULL) {
    bool ok = false;
    if (a.size() == b.size()) {
        auto iterA = a.begin();
        auto iterB = b.begin();
        while (*iterA == *iterB) {
            iterA++;
            iterB++;
        }

        if (iterA == a.end()) {
            ok = true;
        }
    }

    if (!ok) {
        if (msg != NULL) {
            cout << "assertFalse :: Error :: " << msg << endl;
        } else {
            throw new exception();
        }
    }
}

#endif // PROJECTEULER_TESTING
