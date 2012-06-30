def findtrignum(c):
	return int(0.5*c*(c+1))	

def findnum(val):
	intg=2
	c=2
	while True:
		if val%intg==0:
			c+=1
		if intg > 0.5*val:
			break
		intg+=1
	return c

