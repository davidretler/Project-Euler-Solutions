import math
def trignum(num):
	return num*(num+1)/2
def checkpnum(num):
	if (float((1+math.sqrt(24*num+1))/6)-float(int((1+math.sqrt(24*num+1))/6)))==0:
		return True
	else:
		return False
def checkhnum(num):
	if (float((1+math.sqrt(8*num+1))/4)-float(int((1+math.sqrt(8*num+1))/4)))==0:
		return True
	else:
		return False
i=286
while True:
	if checkpnum(trignum(i)) and checkhnum(trignum(i)):
		print trignum(i)
		break
	i+=1

