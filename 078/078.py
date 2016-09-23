# http://mathworld.wolfram.com/PartitionFunctionP.html
# @task 078
# @answer 55374

from itertools import chain

def flatten(l):
	return list(chain.from_iterable(l))

def upto(n):
	penta = (flatten([[(i * (3 * i - 1) / 2), (i * (3 * i + 1) / 2)] for i in range(1, n)]))

	answer = -1
	r = [1] + [0] * (n - 1)
	for i in range(1, n):
		j = 0
		while penta[j] <= i:
			r[i] += (1 if j % 4 < 2 else -1) * r[i - penta[j]]
			r[i] %= int(1e6)
			j += 1

		if r[i] == 0:
			answer = i
			break

	return answer

print upto(100000)
