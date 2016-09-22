# @task 072
# @answer 303963552391

def primes(n):
	a = range(0, n)
	a[1] = 0
	i = 2
	p = []
	while i < n:
		if a[i]:
			p.append(i)
			j = 2 * i
			for j in range(i, n, i):
				a[j] = 0
		i += (i % 2) + 1 
	return p

def phi(n):
	i = 0
	res = 1
	while p[i] * p[i] <= n:
		power = 1
		while n % p[i] == 0:
			n /= p[i]
			power *= p[i]
		res *= (power - (power / p[i]))
		i += 1

	if n > 1:
		res *= (n - 1)

	return res

limit = int(1e6) + 1
p = primes(limit)
print sum(phi(i) for i in xrange(2, limit))
