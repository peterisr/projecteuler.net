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

#endif // PROJECTEULER_TESTING
