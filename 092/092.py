# @task 092
# @answer 8581146

def transform(n):
	r = 0
	while n:
		d = n % 10
		r += d * d
		n /= 10
	return r

def leads_to(i):
	while i != 1 and i != 89:
		i = transform(i)
	return i

def count_leading_to(target, upto):
	leads_to_target = {}
	for i in xrange(1, 1000):
		if leads_to(i) == target:
			leads_to_target[i] = 1

	s = 0
	for i in xrange(1, upto):
		if transform(i) in leads_to_target:
			s += 1

	return s

print count_leading_to(89, int(1e7))
