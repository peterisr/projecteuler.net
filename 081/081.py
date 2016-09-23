# @task 081
# @answer 427337

def read(fname):
	M = []
	with open(fname) as f:
		for line in [x.strip('\n') for x in f.readlines()]:
			M.append(map(int, line.split(',')))

	return M

def minSum(M):
	n = len(M)

	dp = [0] * n
	for i in range(n):
		dp[i] = [0] * n

	inf = int(1e20)
	for i in range(n):
		for j in range(n):
			left = dp[i][j - 1] if j - 1 >= 0 else inf
			top = dp[i - 1][j] if i - 1 >= 0 else inf

			m = min(left, top)
			dp[i][j] = (m if m != inf else 0) + M[i][j]

	return dp[n - 1][n - 1]

print minSum(read("p081_matrix.txt"))
