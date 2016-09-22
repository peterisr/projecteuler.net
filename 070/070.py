# @task 070
# @answer 8319823

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

def is_perm(a, b):
	return sorted(str(a)) == sorted(str(b))

def constructive_solution():
	limit = int(1e7)
	best_ratio = 10
	p = primes(limit)
	for ii in xrange(len(p)):
		i = p[ii]
		for jj in xrange(ii, len(p)):
			j = p[jj]
			n = i * j
			if n > limit:
				break

			if i == j:
				phi = i ** 2 - i
			else:
				phi = (i - 1) * (j - 1)
			ratio = (n + 0.0) / phi

			if best_ratio > ratio and is_perm(n, phi):
				best_ratio = ratio
				best_n = n
	return best_n

print constructive_solution()
