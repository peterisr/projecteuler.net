# @task 087
# @answer 1097343

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

def cnt(upto):
	p = primes(int(upto ** 0.5 + 100))
	p_cnt = len(p)
	p_sq = [i * i for i in p]

	i = j = k = 0
	marks = [0] * upto
	while i < p_cnt and p_sq[i] < upto:
		j = 0
		while j < p_cnt and p_sq[i] + p_sq[j] * p[j] < upto:
			k = 0
			while k < p_cnt and p_sq[i] + p_sq[j] * p[j] + p_sq[k] * p_sq[k] < upto:
				marks[p_sq[i] + p_sq[j] * p[j] + p_sq[k] * p_sq[k]] = 1
				k += 1
			j += 1
		i += 1

	return sum(marks)

print cnt(int(5e7) + 1)
