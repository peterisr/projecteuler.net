# @task 065
# @answer 272

h = [2, 3]
k = [1, 1]

# 2; 1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...
for i in range(2, 100):
	if (i + 1) % 3 == 0: 
		an = (i + 1) / 3 * 2
	else:
		an = 1

	h.append(an * h[i - 1] + h[i - 2])
	k.append(an * k[i - 1] + k[i - 2])

print sum(map(int, str(h[99])))
