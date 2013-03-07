/**
 * Starting in the top left corner of a 2x2 grid,
 * and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 *     *drawings*
 *
 * How many such routes are there through a 20x20 grid?
 *
 * @task 015
 * @answer 137846528820
 */
#include "../projecteuler.h"

ULL solve015() {
    ULL board[21][21];
    F(i,21) board[i][0] = 1;
    F(i,21) board[0][i] = 1;

    FOR(r,1,21) {
        FOR(c,1,21) {
            board[r][c] = board[r][c-1] + board[r-1][c];
        }
    }

    return board[20][20];
}

int main() {
    cout << solve015();
    return 0;
}
