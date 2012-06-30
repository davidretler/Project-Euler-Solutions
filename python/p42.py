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
def gettrignum(num):
	return 0.5*num*(num+1)
with open('words.txt','r') as file:
	contents=file.read()
file.close()
words=makearray(contents)
sm=0
for word in words:
	i=1
	while gettrignum(i) <= getval(word):
		if gettrignum(i)==getval(word):
			sm+=1
			break
		i+=1
print sm
