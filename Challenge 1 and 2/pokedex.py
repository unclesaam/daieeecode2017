import re


class Pokedex:
	
	pokemons = []

	def __init__(self):
		with open("pokemons_list.csv",'r') as f:
			for line in f:
				vals = line.split('|')
				if vals[0] == "Index": continue
				pokemon = Pokemon(*line.split('|')[:-1])
				self.pokemons.append(pokemon)

	def search_pokemon(self,number=None,name="",ptype=None):
		results = []
		for pokemon in self.pokemons:
			if pokemon.name.lower() == name.lower() or \
			pokemon.number == number or \
			ptype in pokemon.ptypes:
				results.append(pokemon)
		return results



class Pokemon:

	def __init__(self,number,name,ptypes):
		self.number = int(re.sub("#","",number))
		self.name = name
		self.ptypes = re.sub(" ","",ptypes).split(',')

	def __repr__(self):
		return "%s: His number is #%s and he is of type %s"%(
			self.name,self.number," and ".join(self.ptypes))

	def __str__(self):
		return self.__repr__()



if __name__ == "__main__":
	pokedex = Pokedex()
	print(pokedex.search_pokemon(number=26))
	print(pokedex.search_pokemon(name="Nidorina"))
	for p in pokedex.search_pokemon(ptype="Fairy"):
		print(p)