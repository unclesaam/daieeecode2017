import re


class Pokedex:
	
	pokemons = []

	def __init__(self):
		with open("pokemons_list.csv",'r') as f:
			for line in f:
				vals = line.split('|')
				pokemon = Pokemon(*line.split('|')[:-1])
				print(pokemon)




class Pokemon:

	def __init__(self,number,name,ptypes):
		self.number = number
		self.name = name
		self.ptypes = re.sub(" ","",ptypes).split(',')

	def __str__(self):
		return "%s: His number is %s and he is of type %s"%(
			self.name,self.number," and ".join(self.ptypes))



if __name__ == "__main__":
	pokedex = Pokedex()