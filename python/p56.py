from math import log

def nth_digit_of(num, n):
	return num / 10**n % 10

def digital_sum(num):
	sum = 0;
	for i in range(0, int(log(num)/log(10))+1):
		sum = sum + nth_digit_of(num, i)
	return sum


max = 0
for a in range(1,100):
	for b in range(1,100):
		curr = digital_sum(a**b)
		if curr > max:
			max = curr
			
print max
