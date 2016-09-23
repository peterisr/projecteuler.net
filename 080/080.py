# @task 080
# @answer 40886

def isqrt(n):
    x = n
    y = (x + 1) // 2
    while y < x:
        x = y
        y = (x + n // x) // 2
    return x

def rootDigitSum(r):
	s = 0
	for i in r:
		num = i * (10 ** 300)
		root = isqrt(num)
		if root * root != num:
			digits = [int(i) for i in str(root)]
			s += sum(digits[:100])

	return s

print rootDigitSum(range(1, 101))
