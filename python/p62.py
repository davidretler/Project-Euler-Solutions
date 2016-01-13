from math import log, floor

def digits_in(number):
	# Decimal digits in the number
	if number == 0:
		return 1
	else:
		return int(floor(log(number,10)) + 1)

def digit_list(number):
	# Returns a list of the digits in number
	d_list = [[],] * digits_in(number)
	for i in xrange(0, len(d_list)):
		d_list[i] = number / (10**i) % 10
	return d_list
	
def number_from_list(d_list):
	# Reconstruct a number from the list of its digits
	sum = 0
	for i in xrange(0, len(d_list)):
		sum = sum + d_list[i] * 10**i
	return sum
	
def digit_count(number):
	# Returns a length 10 array of all the digits in the number
	count = [0,] * 10
	for d in digit_list(number):
		count[d] = count[d] + 1
	return count


def is_perm_of(num_a, num_b):
	# Returns true if and only if num_b is a permuatation of num_a
	if digits_in(num_a) != digits_in(num_b):
		return False
	else:
		list_a = digit_count(num_a)
		list_b = digit_count(num_b)
		for i in xrange(0, 10):
			if list_a[i] != list_b[i]:
				return False
		return True
	
	
NUMBER_OF_PERMS = 5
	
for i in xrange(1001,10000):
	number = 1
	for j in xrange(i - 1, 0, -1):
		if is_perm_of(i**3, j**3):
			number = number + 1
			if number == NUMBER_OF_PERMS:
				break
	if number == NUMBER_OF_PERMS:
		print j
	#print str(i) + "\t" + str(number)
