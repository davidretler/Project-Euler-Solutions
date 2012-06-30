def makearray(strg):
	check=True
	c=0
	a=[]
	for char in strg:
		if check:
			if not char=="\"":
				a.append(char)
				check=False
		else:
			if not char==',':
				if not char=="\"":
					a[c]+=char
			else:
				check=True
				c+=1
	return a
def getval(name):
	val=0
	abc=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
	for char in name:
		val+=abc.index(char)+1
	return val
with open('names.txt', 'r') as file:
	contents=file.read()
file.close()
names=makearray(contents)
namesalph=sorted(names)
val=0
for name in namesalph:
	val+=getval(name)*(1+namesalph.index(name))
print val
