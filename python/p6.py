#Prodject Euler Question 6
#Find the Diff between (1+2+...100)**2 and (1**2+2**2+...100**2)
#David Etler
#22 NOV 2011

i=0
nums=[]
while i <= 99:
	i += 1
	nums.append(i)
sum=0
sumsqr=0
sqrsum=0
for num in nums:
	sum += num
	sqrsum += num**2
sumsqr=sum**2
print sumsqr-sqrsum
