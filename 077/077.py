# @task 077
# @answer 71

import bisect

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

def ways(n):
	primes_ = primes(n)

	ways = [1, 0] + ([0] * (n - 2))
	for p in primes_:
		for i in xrange(0, n - p):
			ways[i + p] += ways[i]

	return ways

print bisect.bisect_left(ways(1000), 5000)
