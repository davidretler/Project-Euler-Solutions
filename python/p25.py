#Project Euler Number 25
#What is the first term in the Fibonacci sequence to contain 1000 digits?#
#David Etler
#22 NOV 2011

f1=1
f2=1
c=2
d=0
while d == 0:
	i=f1+f2
	f1=f2
	f2=i
	if len(str(i)) == 1000:
		d=1
	c+=1
	print [c, len(str(i))]
