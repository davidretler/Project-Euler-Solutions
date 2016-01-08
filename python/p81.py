
# one iteration of the algoirith,
def iterate(matrix, n):
	if n <= len(matrix):
	 	x = n
	 	y = 1
	else:
	 	x = len(matrix)
	 	y = 1 + n - len(matrix)
	 	
	while x >= 1 and y <= len(matrix):
	 

	 	if y - 1 >= 1 and x - 1 >= 1:
	 		matrix[x-1][y-1] = matrix[x-1][y-1] + min(matrix[x-2][y-1], matrix[x-1][y-2])
	 	elif x - 1 < 1:
	 		matrix[x-1][y-1] = matrix[x-1][y-1] + matrix[x-1][y-2]
	 	else:
	 		matrix[x-1][y-1] = matrix[x-1][y-1] + matrix[x-2][y-1]

	 	x = x - 1
	 	y = y + 1

def load_matrix():
	matrix = []
	
	with open("p081_matrix.txt") as file:
	
		lines = file.readlines()

		i = 0
		for line in lines:
			matrix.insert(i,[])
			for num in line.strip("\n").split(","):
				matrix[i].insert(len(matrix[i]), int(num))
			i = i + 1
		

	return matrix	

def print_matrix(matrix):
	print "\n"
	
	for i in range(0, len(matrix)):
		print matrix[i]

matrix = load_matrix()

for i in range(2, 2 * len(matrix)):
	iterate(matrix, i)

print matrix[len(matrix)-1][len(matrix)-1]

