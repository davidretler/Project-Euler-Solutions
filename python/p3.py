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
val=600851475143
intg=0
while val != 1:
	done=0
	intg=1
	while done==0:
		if val%2==0:
			val=val/2
			if val/2==1:
				print 2
			break
		elif checkprime(intg)==0 and val%intg==0:
			val=val/intg
			if val/intg==0:
				print intg
			break
		else:
			intg+=2
