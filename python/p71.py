list = []
__gcds = {} # Remember old values
__LIMIT = 1000

def gcd(p ,q):
	if q > p: return gcd(q,p)
	if q == 0: return p
	if q == 1: return 1
	
	try:
		the_gcd = __gcds[(p, q)]
	except:
		the_gcd = gcd(q, p % q) # Euclid's formula
		if p <= __LIMIT:
			__gcds[(p, q)] = the_gcd
	
	return the_gcd
	

sum = 0
for i in range(0, 1000000):
	for j in range(i, 1000000):
		if gcd(i, j) == 1:
			sum = sum + 1
			
print sum
			
			
