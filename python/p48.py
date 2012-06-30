a=[]
i=1
while i<=1000:
	a.append(i**i)
	i+=1
sum=0
for num in a:
	sum+=num
str=str(sum)
print [str[3001-10], str[3001-9], str[3001-8], str[3001-7], str[3001-6], str[3005-5], str[3001-4], str[3001-3], str[3001-2], str[3001-1]]
