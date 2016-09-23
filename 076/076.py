# https://en.wikipedia.org/wiki/Partition_%28number_theory%29
# @task 076
# @answer 190569291

n = 100
cache = [-1] * (n + 1)

def p(n):
	if n < 0: 
		return 0
	elif n == 0:
		return 1
	else:
		if cache[n] == -1:
			s = 0
			for k in range(-n - 1, n + 1):
				gk = k * (3 * k - 1) / 2
				if gk > 0 and gk <= n:
					s += int((-1) ** (k - 1)) * p(n - gk)
			cache[n] = s
		return cache[n]

print p(100) - 1
