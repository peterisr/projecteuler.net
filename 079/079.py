# @task 079
# @answer 73162890

from itertools import permutations

def read(fname):
	with open(fname) as f:
		return [x.strip('\n') for x in f.readlines()]

def satisfies(s, c):
	return s.find(c[2], s.find(c[1], s.find(c[0]))) != -1

def minCode(constraints):
	used_digits = [0] * 10
	s = []
	for c in constraints:
		u = [0] * 10
		for d in c:
			u[int(d)] += 1

		for i in range(10):
			if u[i] > used_digits[i]:
				for j in range(u[i] - used_digits[i]):
					s.append(str(i))
				used_digits[i] = u[i]

	for p in permutations(sorted(s)):
		solution = "".join(p)
		if all([satisfies(solution, c) for c in constraints]):
			return solution

print minCode(read("keylog.txt"))
