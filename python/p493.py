TOTAL = 12		# total balls
CHOOSE = 6		# number of bals to choose
EACH_COLOR = 2	# number of balls of each color



# copies all elements of a into b
def copy_a_to_b(a, b):
	try:
		for i in range(0, len(a)):
			b.insert(i, a[i])
	except:
		print "Invalid dimensions"

def prod(i, j):
	# Returns i * (i + 1) * ... * j
	if i > j: return prod(j,i)
	the_prod = 1
	for x in range(i, j + 1):
		the_prod = the_prod * x
	return the_prod
	
def ways(m):
	n = sum(m)
	curr_sum = prod(1,n)
	for ni in m:
		curr_sum = curr_sum / prod(1, ni)
	return curr_sum

def nPr(n,r):
	return prod(n, n - r + 1)
	
def nCr(n, r):
	return prod(n, n - r + 1) / prod(1, r)
	
def probability_r(n, nums, i):
	# probablility of choosing n different colors where nums[i] is the number we chose of the ith color
	# recursive i is the current index we're chosing
	
	if i == len(nums) - 1:
		
		# we're on the last numbers, this is our base case
		nums[i] = CHOOSE - sum(nums) + nums[i] # number we need of the last color
		if nums[i] <= EACH_COLOR and nums[i] > 0 and (i == 0 or nums[i] >= nums[i-1]):
			try:
				assert sum(nums) == CHOOSE
			
				product = 1
				total_left = TOTAL
				for ni in nums:
					product = product * prod(EACH_COLOR, EACH_COLOR - ni + 1) / float(prod(total_left, total_left - ni + 1))
					total_left = total_left - ni
			
				assert total_left == TOTAL-CHOOSE # should have taken care of every ball, chose 
				
				# multiply by number of ways to choose each colors, times ways colors can be relatively ordered
				product = product * nCr(TOTAL/EACH_COLOR, n) * ways(nums)
				print str(product) + "\t" + str(nums)
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
		for ni in range(nums[i-1], EACH_COLOR + 1):
			nums[i] = ni
			the_sum = the_sum + probability_r(n, nums, i + 1)
		return the_sum
			
		
			
	
def probability(n):
	# the probablility of chosing exactly n distinct colors
	if n < CHOOSE / EACH_COLOR: return 0
	if n == 1: return probability_r(n, [0], 0)
	
	nums = [0,]*n # array list to hold the numbers of each color choses (c1,...,cn)
	
	the_sum = 0
	for i in range(1,EACH_COLOR+1):
		nums[0] = i
		the_sum = the_sum + probability_r(n, nums, 1)
	return the_sum
		

#p1 = 0
#p2 = prod(1,10)**2 / (1.*prod(70,51))

the_sum = 0
for i in range(1, TOTAL/EACH_COLOR + 1):
	curr_prob = probability(i)
	the_sum = the_sum + curr_prob
	print str(i) + "\t" + str(curr_prob)
	
print the_sum
	
	
#print probability(2)
