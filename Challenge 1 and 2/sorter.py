def find(nom_scramble):
 
    pokedex = Pokedex()
    nom_scramble = nom_scramble.lower()
 
    for poke in pokedex.pokemons:
        #print("%s, %s"%(len(poke.name), len(nom)))
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
    print('sorter')
 
print(find("sqitlure"))