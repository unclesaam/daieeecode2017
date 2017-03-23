#include <iostream>
#include <fstream>
#include <string>
 
 
using namespace std;
 
 
 
int main () {
 
    string texte;
    string file_contents;
    string mot;
    ifstream file;
    file.open ("data");
     
    while(!file.eof())
    {
        getline(file,texte);
        file_contents += texte;
        file_contents.push_back('\n');
 
    }
    /*Faire une liste de tous les mots qui apparaissent dans le texte*/
    /*Itérer sur cette liste, créer une nouvelle colonne pour un nouveau mot*/
    /*Ajouter au compteur pour un mot déjà existant*/
 
 
 
 
    cout << file_contents << endl;
 
 
 
 
 
    /*cout << file_contents;*/
 
    return 0;
 
 
}