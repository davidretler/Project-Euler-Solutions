
HandTypes = {'Royal Flush': 10,'Straight Flush': 9,'Four Of A Kind': 8,'Full House': 7,'Flush': 6,'Straight': 5,'Three Of A Kind': 4,'Two Pairs': 3,'One Pair': 2,'High Card': 1}

CardValues = {'2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'T':10, 'J':11, 'Q':12, 'K':13, 'A':14}


class Hand:

	def __init__(self, cards=[]):
	
		if (type(cards) == str):
			self.cards = cards.split(" ")
		elif type(cards) == list:
			self.cards = cards	
			
		tmp = self.parse_hand()
		#self.type = tmp[0]
		#self.card_val = tmp[1]
		
	
	def __str__(self):
		return " ".join(self.cards)
		
	# parse the hand to find the hand type and card value
	def parse_hand(self):
		self.sort_cards()
		
		if self.royal_flush():
			self.type = 'Royal Flush'
			self.card_val = 'A'
		elif self.straight_flush():
			self.type = 'Straight Flush'
			self.card_val = self.cards[0][0]
		elif self.four_of_a_kind():
			self.type = 'Four Of A Kind'
			self.card_val = self.cards[1][0]
			
			
						
		
	def sort_cards(self):
		# naive selection sort works because hand is always 5 cards 
		for i in range(0,5):
			largest = i
			for j in range(i+1, 5):
				if CardValues[self.cards[largest][0]] < CardValues[self.cards[j][0]]:
					largest = j
			tmp = self.cards[i]
			self.cards[i] = self.cards[largest]
			self.cards[largest] = tmp
	
	def royal_flush(self):
		
		if not self.same_suit():
			return False
		else:		
			return self.cards[0][0] == 'A' and self.cards[1][0] == 'K' and self.cards[2][0] == 'Q' and self.cards[3][0] == 'J' and self.cards[4][0] == 'T' 
		
	def straight_flush(self):
		
		if not self.same_suit():
			return False
		else:
			curr = CardValues[self.cards[0][0]]
			for i in range(1,5):
				curr = curr - 1
				if CardValues[self.cards[i][0]] != curr:
					return False
			return True
	
	def four_of_a_kind(self):
		
		# check if first 4 make 4 of a kind		
		if self.same_val(0,4):
			return True
		else:
			return self.same_val(1,5)
		
	def full_house(self):
		
		# check if first 3 make 3 of a kind
		
		val = self.cards
		
		
	# check if cards i through j have the same value
	def same_val(self, i, j):
		val = self.cards[i][0]
		for t in range(i+1, j):
			if self.cards[t][0] != val:
				return False
		return True
	
	def same_suit(self):
		# check that all cards are same suit
		suit = self.cards[0][1]
		for i in range(1, 5):
			if self.cards[i][1] != suit:
				return False
		return True
