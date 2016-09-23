# @task 085
# @answer 2772

def getRectangleCnt(n, m):
	A = [0] * (n + 1)
	for i in range(n + 1):
		A[i] = [0] * (m + 1)

	s = 0
	for i in range(1, n + 1):
		for j in range(1, m + 1):
			A[i][j] = A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1] + 1
			s += A[i][j]

	return s

def getBestArea():
	limit = 100
	close_to = int(2e6)
	best_area = int(1e9)
	nearest = 0
	for i in range(1, limit):
		for j in range(i, limit):
			area = i * j
			rc = getRectangleCnt(i, j)
			if abs(close_to - rc) < abs(close_to - nearest):
				nearest = rc
				best_area = area
				print i, j, rc, area

	return best_area

print getBestArea()
