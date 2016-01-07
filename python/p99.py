from math import log

list = []

i = 0
with open("p099_base_exp.txt") as file:
	lines = file.readlines()
	
	for line in lines:
		line = line.strip('\n')
		
		base = int(line.split(",")[0])
		exp = int(line.split(",")[1])
		
		list.append(log(base)*exp)

print list.index(max(list)) + 1 # add one as line 1 is index 0
