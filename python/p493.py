TOTAL = 70		# total balls
CHOOSE = 20		# number of bals to choose
EACH_COLOR = 10	# number of balls of each color


def prod(i, j):
	# Returns i * (i + 1) * ... * j
	if i > j: return prod(j,i)
	the_prod = 1
	for x in range(i, j + 1):
		the_prod = the_prod * x
	return the_prod
	
def probability_r(n, nums, i):
	# probablility of choosing n different colors where nums[i] is the number we chose of the ith color
	# recursive i is the current index we're chosing
	if i == len(nums) - 1:
		# we're on the last numbers, this is our base case
		nums[i] = CHOOSE - sum(nums) + nums[i] # number we need of the last color
		if nums[i] <= EACH_COLOR and nums[i] > 0:
			product = 1
			total_left = TOTAL
			for ni in nums:
				product = product * prod(1, ni)
				total_left = total_left - ni
			try:
				assert total_left == TOTAL-CHOOSE # should have taken care of every ball, chose 
				#print str(product) + "\t" + str(nums)
				return product
			except:
				print "ASSERT ERROR " + str(total_left)
				return 0
			
		else:
			#print "ERROR: " + str(nums)
			return 0 # impossible because we need more then EACH_COLOR for the last one or we need less than 1
	else:
		# recursive case, try all possibilities for nums[i]
		the_sum = 0
		for ni in range(1,11):
			nums[i] = ni
			the_sum = the_sum + probability_r(n, nums, i + 1)
		return the_sum
			
		
			
	
def probability(n):
	# the probablility of chosing exactly n distinct colors
	if n < CHOOSE / EACH_COLOR: return 0
	
	nums = [0,]*n # array list to hold the numbers of each color choses (c1,...,cn)
	
	the_sum = 0
	for i in range(1,EACH_COLOR+1):
		nums[0] = i
		the_sum = the_sum + probability_r(n, nums, 1)
	return the_sum
		

p1 = 0
p2 = prod(1,10)**2 / (1.*prod(70,51))

the_sum = 0
for i in range(1,8):
	the_sum = the_sum + probability(i)
	print str(i) + "\t" + str(probability(i))
	
print the_sum
	
	
#print probability(7)
