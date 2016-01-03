from math import *

def digits(num):
	t = floor(log(num,10)+1)
	if num < 10**t:
		return t
	else:
		return t+1

# n-digit numbers
sum = 0
for n in range(1,22):
	a = 1
	while digits(a**n) < n+1:
		if digits(a**n) == n:
			print str(a) + ', ' + str(n) + ', ' + str(a**n)
			#print str(digits(a**n)) + "==" + str(n)
			sum = sum + 1
		a = a + 1
	
print sum
		
