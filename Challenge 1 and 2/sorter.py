from pokedex import Pokedex
import re

def find_pokemon_name(nom_scramble):
 
    pokedex = Pokedex()
    nom_scramble = nom_scramble.lower()
 
    for poke in pokedex.pokemons:
        pokeNom = list(poke.name.lower())
        for lettre1 in nom_scramble:
            if lettre1 in pokeNom:
                pokeNom.remove(lettre1)
            else:
                break
 
        if not pokeNom:
            return poke.name
 
    return "no pokemon found"
 

 
if __name__ == "__main__":
    with open('pokemon_names_to_reorder.txt', "r") as f:
        for name in f:
            name_clean = re.sub("\n","",name)
            print("%s: %s"%(name_clean,find_pokemon_name(name_clean))) 
