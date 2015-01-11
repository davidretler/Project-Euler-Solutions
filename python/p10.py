import math
def checkprime(num):
	isprime=0
	i=1
	while i <= math.sqrt(num):
		if num==1:
			isprime=1
			break
		if (num%3)==0 and num!=3:
			isprime=1
			break
		if (num%2)==0 and num!=2:
			isprime=1
			break
		if (num%i)==0 and num!=i and i!=1:
			isprime=1
			break
		i+=2
	return isprime
sm=2
i=1
while i < 2000000:
	if checkprime(i)==0:
		sm+=i
	i+=2
print sm
