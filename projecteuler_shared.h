/**
 * Code that is shared between multiple tasks,
 * but is not general enough to put in "projecteuler_code.h".
 */
#ifndef PROJECTEULER_SHARED
#define PROJECTEULER_SHARED 1

#include "projecteuler.h"

UI pyramidMaximizePath(const vector<VI> &pyramid, UI lines) {
    UI maximizeCost[lines][lines];

    //TRACE2DS(pyramid);

    maximizeCost[0][0] = pyramid[0][0];
    FOR(i, 1, lines) {
        F(j, pyramid[i].size()) {
            int l = j - 1, r = j;
            UI m = 0;
            if (l >= 0) {
                m = maximizeCost[i - 1][l];
            }

            if (r < pyramid[i - 1].size()) {
                m = MAX(m, maximizeCost[i - 1][r]);
            }

            maximizeCost[i][j] = m + pyramid[i][j];
        }
    }

    //TRACE2D(maximizeCost, lines, lines);

    UI max = maximizeCost[lines - 1][0];
    F(i, pyramid[lines - 1].size()) {
        max = MAX(max, maximizeCost[lines - 1][i]);
    }

    return max;
}

UI pyramidMaximizePathFromFile(const char *file, UI lines) {
    ifstream in("input018.txt");

    vector<VI> pyramid;
    pyramid.resize(lines);

    UI lineLength = 1;
    F(i,lines) {
        F(j,lineLength) {
            UI tmp;
            in >> tmp;
            pyramid[i].push_back(tmp);
        }

        lineLength++;
    }

    UI result = pyramidMaximizePath(pyramid, lines);

    in.close();
    return result;
}

#endif
