# @task 073
# @answer 7295372

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def fractionsInRange():
	s = 0
	for i in xrange(1, 12001):
		x = i / 3 + 1
		y = (i + 1) / 2 - 1
		s += len([j for j in xrange(x, y + 1) if gcd(j, i) == 1])

	return s

print fractionsInRange()
