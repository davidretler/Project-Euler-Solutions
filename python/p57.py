from math import log

def digits_in(n):
	return int(floor(log(n)/log(10)) + 1)

def con_sqrt(n):
	bottom = Fraction(2,1)
	for i in range(0,n):
		bottom = 2 + 1/bottom
	return 1 + 1/bottom


sum = 0
for n in range(0,1000):
	curr = con_sqrt(n);
	num = curr.numerator
	dem = curr.denominator
	if(digits_in(num) > digits_in(dem)):
		sum = sum + 1

print sum
