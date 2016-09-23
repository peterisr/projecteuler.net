# @task 074
# @answer 402

from operator import mul
from itertools import combinations_with_replacement

def product(list):
	return reduce(mul, list, 1)

def factorial(n):
	return product(xrange(1, n + 1))

def toKey(num):
	if type(num) is tuple:
		return "".join(sorted(map(str, num)))
	else:
		return "".join(sorted(str(num)))

mapping = {}
for digits in range(1, 8):
	for p in combinations_with_replacement(range(0, 10), digits):
		maps_to = sum(map(factorial, p))
		mapping[toKey(p)] = toKey(maps_to)

lengths = {}
for key in mapping:
	lengths[key] = 0

	i = key
	k = {}
	while not i in k:
		lengths[key] += 1
		k[i] = 1
		i = mapping[i]

answer = sum([1 for i in xrange(1, 10 ** 6) if lengths[toKey(i)] == 60])
print answer
