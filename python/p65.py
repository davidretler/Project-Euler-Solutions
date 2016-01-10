from math import log, ceil
from fractions import Fraction

def sum_of_digits(num):
	_sum = 0
	for i in range(0, int(ceil(log(num,10)))):
		_sum = _sum + num / 10**i % 10
	return _sum

def con_e(n):
	bottom = Fraction(1,1)
	for i in range(n-2,0-1,-1):
		if (i+2) % 3 == 0:
			#print (i+2)/3*2
			bottom = (i+2)/3*2 + 1/bottom
		else:
			#print 1
			bottom = 1 + 1/bottom
	return 2 + 1/bottom


print sum_of_digits(con_e(99).numerator)
