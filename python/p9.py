import math
a=1
done=0
while done==0:
	var=(((1000*a)-500000)/(a-1000))
	if var==float(int(var)):
		t=int(var)
		pvar=math.sqrt(t**2+a**2)
		if pvar==float(int(pvar)):
			print t*a*int(pvar)
			done=1
	a+=1
