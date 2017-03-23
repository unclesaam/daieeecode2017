import re


class Pokedex:
	
	pokemons = []

	def __init__(self):
		with open("pokemons_list.csv",'r') as f:
			for line in f:
				vals = line.split('|')
				print(vals[:-1])
				pokemon = Pokemon(*line.split('|')[:-1])




class Pokemon:

	def __init__(self,number,name,ptypes):
		self.number = number
		self.name = name
		self.ptypes = ptypes.split(',')

	def __str__(self):
		return "%s: His number is %s and he is of type %s"%(
			self.name)



if __name__ == "__main__":
	pokedex = Pokedex()