from math import log, floor

cdef int digits_in(number):
	# Decimal digits in the number
	if number == 0:
		return 1
	else:
		try:
			return int(floor(log(number,10)) + 1)
		except:
			print number

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

cdef bint is_cube(number):
	# Returns True if and only if the number is the cube of an integer
	cdef double root = number**(1/3.)
	return round(root)**3 == number

cdef int test_permutations_r(digit_count, perm, int i, int total):
	cdef int n, start
	
	if i == len(perm):
		# base case, we have selected all the digits_in
		
		# test preconditions
		#for c in digit_count:
		#	assert c == 0
		#for d in perm:
		#	assert type(d)==int
		
		the_num = number_from_list(perm)
		if is_cube(the_num):
			#print the_num
			return total + 1
		
	else:
		# recursively find all permuatations
		start = 1 if i == 0 else 0 # don't allow leading 0s
		for n in xrange(start, 10):
			# for each digit we have to use, test all permuatations where the ith digit is n
			if digit_count[n] != 0:
				digit_count[n] = digit_count[n] - 1
				perm[i] = n
				total = test_permutations_r(digit_count,  perm, i + 1, total)
				digit_count[n] = digit_count[n] + 1
				perm[i] = []
				
	return total
		
	

cdef int test_permutations(number):
	perm = [[],] * digits_in(number)
	return test_permutations_r(digit_count(number), perm, 0, 0)
	
	
#cdef int i
#for i in xrange(1001, 10000):
#	if test_permutations(i**3) == 5:
#		print str(i) + "\t" + str(test_permutations(i**3))
#		break
#	if i % 1000 == 1:
#		print i

print test_permutations(5027**3)
