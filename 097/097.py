# @task 097
# @answer 8739992577

def mod_pow(b, p, m):
	if p == 0:
		return 1
	else:
		res = mod_pow(b, p / 2, m)
		res *= res
		res %= m

		if p % 2 == 1:
			res *= b
			res %= m

		return res

def last_digits(digits):
	m = int(10 ** digits)
	return (28433 * mod_pow(2, 7830457, m) + 1) % m

print last_digits(10)
