# See https://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples
# @task 075
# @answer 161667

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

max_l = 1500000

l = [0] * (max_l + 1)
n = 0
while 2 * n * n <= max_l:
	n += 1
	m = n
	while True:
		while 2 * m * m <= max_l and ((m - n) % 2 != 1 or gcd(m, n) != 1):
			m += 1

		k = 1
		while True:
			a = k * (m ** 2 - n ** 2)
			b = k * (2 * m * n)
			c = k * (m ** 2 + n ** 2)

			L = a + b + c
			if L > max_l:
				break;

			l[L] += 1
			k += 1

		if k == 1:
			break;

		m += 1

answer = sum(1 for i in l if i == 1)
print answer
