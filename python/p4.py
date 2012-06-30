def checkpal(num):
	pal=0
	strn=str(num)
	lenn=len(strn)
	i=0
	while i < lenn:
		if strn[i]==strn[(lenn-1)-i]:
			pal=0
			i+=1
		else:
			pal=1
			break
	return pal
i=100
a=[]
b=[]
while i <= 1000:
	a.append(i)
	i+=1
for i in a:
	for n in a:
		if checkpal(i*n)==0:
			b.append(i*n)
print sorted(b)[len(b)-1]
