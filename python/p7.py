a=[]
c=0
i=2
while c <= 10001:
	num=1
	isprime=0
	#print "testing if", i, "is prime"
	while num <= math.sqrt(i):
		#print "checking for divisibility by", num
		if (i%num)==0 & i!=num & num!=1:
			isprime=1
		num += 1
	if isprime==0:
		#print i
		print (c/10001)
		a.append(i)
		c += 1
	i+=1
