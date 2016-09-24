# @task 090
# @answer 1217

from itertools import combinations

def is_on_die(a, x):
	if x == 6 or x == 9:
		return 6 in a or 9 in a
	else:
		return x in a

def can_produce_num(a, b, num):
	x = num // 10
	y = num % 10

	return (is_on_die(a, x) and is_on_die(b, y)) \
		or (is_on_die(a, y) and is_on_die(b, x))

def is_good_dice(a, b):
	return True \
		and can_produce_num(a, b, 1) \
		and can_produce_num(a, b, 4) \
		and can_produce_num(a, b, 9) \
		and can_produce_num(a, b, 16) \
		and can_produce_num(a, b, 25) \
		and can_produce_num(a, b, 36) \
		and can_produce_num(a, b, 49) \
		and can_produce_num(a, b, 64) \
		and can_produce_num(a, b, 81) \

def count_good_combos():
	c = 0
	for a in combinations(range(0, 10), 6):
		for b in combinations(range(0, 10), 6):
			if a > b:
				continue

			if is_good_dice(a, b):
				c += 1

	return c

print count_good_combos()
