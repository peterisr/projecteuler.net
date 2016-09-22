# @task 068
# @answer 6531031914842725

def bad_str():
	return "000000000000000"

def ray(a, index):
	last = 5 if index == 4 else index + 6
	return [a[index], a[index + 5], a[last]]

def compress(a):
	start = 0
	for i in range(0, 5):
		if a[start] > a[i]:
			start = i

	s = ""
	for i in range(start, start + 5):
		s += "".join(map(str, ray(a, i % 5)))

	return s

def maxNgon(depth = 0, a = [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1]):
	u = {}
	for i in range(0, 10):
		u[a[i]] = 1

	if depth < 7:
		m = bad_str()
		for i in range(1, 11):
			if i in u:
				continue

			a[depth] = i
			s = maxNgon(depth + 1, a[:])
			a[depth] = -1

			m = max(m, s)
		return m
	else:
		ray_sum = sum(ray(a, 0))
		for i in range(7, 10):
			a[i] = ray_sum - a[i - 6] - a[i - 1]
			if (a[i] < 1) or (a[i] > 10) or (a[i] in u):
				return bad_str()
			u[a[i]] = 1

		for i in range(0, 5):
			if sum(ray(a, i)) != ray_sum:
				return bad_str()

		h = compress(a)
		if len(h) != 16:
			h = bad_str()

		return h

print maxNgon()
