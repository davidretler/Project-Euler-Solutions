class fibb:
	s1=1
	s2=2
	f=[s1,s2]
	i=s1+s2
while fibb.i <= 4000000:
	fibb.f.append(fibb.i)
	fibb.i=fibb.s1+fibb.s2
	fibb.s1=fibb.s2
	fibb.s2=fibb.i
sum=0
for num in fibb.f:
	if (num%2)==0:
		sum+=num
print sum
