# Use https://en.wikipedia.org/wiki/Pell%27s_equation .
# 
# @task 066
# @answer 661

def is_perfect_square(n):
	root = int(n**0.5)
	return root * root == n

def gcd(a, b):
	if b == 0: 
		return a
	else:
		return gcd(b, a % b)

def continuedFraction(n):
	nroot = n ** 0.5

	a = 1
	b = 0
	c = 1

	while True:
		x = int((a * nroot + b) / c)
		a1 = a * c
		b1 = -(b * c - c * c * x)
		c1 = a * a * n - b * b + 2 * c * x * b - c * c * x * x

		a = a1
		b = b1
		c = c1

		g = gcd(gcd(a, b), c)
		a /= g
		b /= g
		c /= g

		yield x

def convergents(n):
	h1 = 1
	h2 = 0
	k1 = 0
	k2 = 1

	for a in continuedFraction(n):
		h = a * h1 + h2
		k = a * k1 + k2

		h2 = h1
		h1 = h
		k2 = k1
		k1 = k

		yield (h, k)

mD = -1
mX_sq = -1
for D in range (2, 1001):
	if is_perfect_square(D):
		continue

	for p in convergents(D):
		x_sq = p[0] * p[0]
		y_sq = p[1] * p[1]
		if x_sq - D * y_sq == 1:
			if mX_sq < x_sq:
				mX_sq = x_sq
				mD = D
			break

print mD
