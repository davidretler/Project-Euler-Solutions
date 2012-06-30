a=2
b=2
c=[]
while a<=100:
	while b<=100:
		if not a**b in c:
			c.append(a**b)
		b+=1
	b=2
	a+=1
print len(c)

