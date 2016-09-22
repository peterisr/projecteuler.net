# @task 071
# @answer 428570

def larger(a, b):
	return a[0] * b[1] > a[1] * b[0]:

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def minNumerator():
	best = (2, 5)
	for i in xrange(1, int(1e6)):
		if i * 3 % 7 == 0:
			x = (i * 3 - 1) / 7
		else:
			x = i * 3 / 7

		g = gcd(x, i)
		f = (x / g, i / g)

		if larger(f, best):
			best = f

	return best

print minNumerator()
