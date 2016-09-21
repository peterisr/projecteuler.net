/**
 * @task 069
 * @answer 510510 
 */
#include "../projecteuler.h"

UI solve069() {
	// Using formulas for phi(n), we get 
	//     n / phi(n) = (p_1 * p_2 * ... * p_k) / ((p_1 - 1) * (p_2 - 1) * ... * (p_k - 1));
	// where p_i are prime factors of n.
    // It is easy to see that such an expression is maximized, if p_i are as small/many as possible.
	return 2 * 3 * 5 * 7 * 11 * 13 * 17;
}

int main() {
    cout << solve069();
    return 0;
}
