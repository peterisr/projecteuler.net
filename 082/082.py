# @task 082
# @answer 260324

from heapq import *

def read(fname):
	M = []
	with open(fname) as f:
		for line in [x.strip('\n') for x in f.readlines()]:
			M.append(map(int, line.split(',')))
	return M



def array2d(r, c, init):
	A = [0] * r
	for i in range(r):
		A[i] = [init] * c
	return A



def minPathFrom(M, x, y, directions):
	n = len(M)

	Q = []
	heappush(Q, (M[x][y], x, y))
	costs = array2d(n, n, -1)
	while len(Q) > 0:
		top = heappop(Q)

		cost = top[0]
		cx = top[1]
		cy = top[2]

		if costs[cx][cy] != -1:
			continue

		costs[cx][cy] = cost
		for d in directions:
			nx = cx + d[0]
			ny = cy + d[1]
			if nx >= 0 and nx < n and ny >= 0 and ny < n and costs[nx][ny] == -1:
				heappush(Q, (cost + M[nx][ny], nx, ny))

	return costs



def minPathLeftToRight(M):
	n = len(M)
	best = int(1e20)
	for i in range(n):
		paths = minPathFrom(M, i, 0, [(-1, 0), (1, 0), (0, 1)])
		for j in range(n):
			best = min(best, paths[j][n - 1])
	return best



print minPathLeftToRight(read("p082_matrix.txt"))
