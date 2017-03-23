#include <iostream>
#include <list>
#include <cstdlib>
 
using namespace std;


//Pokemon rooster works usign a Circularly linked list to store data
//This represent an element of the linked list
//It's your job to determine what need to go in there
typedef struct ListNode{
	std::string name;
	std::string type;
	ListNode * p_previous;
	ListNode * p_next;
	int level;
}ListElem;
//---------------------------------------------------------

//pfirst points to the first item of the list
ListElem *pfirst;
//plast points to the last item of the list
ListElem *plast;


// This is an example of the functions you need to implement
// Feel free to ignore them, but the solution was made implementing those function

// Insert pokemonName at position pos in linked list
// First arg is pokemon name, second is pokemon level
// Third is pokemon Type and last one is the position in the list
void Insert (std::string,int, std::string, int);

//delete pokemon at position i from the Circularly Linked List
void Delete(int);

//Print out all pokemon on the screen
void printall(ListElem *L);

//count the number of pokemon in the Circularly Linked List
int countitem(ListElem *L);

//Find pokemon with lowest level
ListElem *findmin(ListElem *L);

//Find pokemon with highest level
ListElem *findmax(ListElem *L);

//Find pokemon with corresponding name
ListElem *find(ListElem *L,std::string);


//Empty the Circularly linked List
void makeEmpty(){
	pfirst=plast=NULL;
}


void showmenu(){
	cout<<"=================================\n";
	cout<<"Pokemon Rooster Menu\n";
	cout<<"=================================\n";
	cout<<"1.Add a Pokemon\n";
	cout<<"2.Delete a Pokemon\n";
	cout<<"3.Show number of Pokemons in rooster\n";
	cout<<"4.Find Pokemon with lowest level\n";
	cout<<"5.Find Pokemon with highest level\n";
	cout<<"6.Find Pokemon\n";
	cout<<"7.Print all Pokemons\n";
	cout<<"8.Exit\n";
}

void select(){
	std::string name, type;
	int pos, ch, level;
	ListElem *temp;
	char continuePrompt='y';
	makeEmpty();
	//Make the list empty

	while(continuePrompt=='y'){ 
		cout<<"Enter your choice:";
		cin>>ch;
		try{
			switch(ch){
				// Add a new pokemon
				case 1: cout<<"Pokemon name :";
					cin>>name;
					cout<<"Pokemon level :";
					cin>>level;
					cout<<"Pokemon type :";
					cin>>type;
					cout<<"Position into the rooster:";
					cin>>pos;
					Insert(name,level,type,pos);
					break;

				// Delete a pokemon	
				case 2: 
					cout<<"Position in rooster:";
					cin>>pos;
					break;

				// Show number of Pokemons in rooster	
				case 3: 
					cout<<"Number of Pokemons:"<< "GIMME YOUR VALUE HERE" << endl;
					break;

				// Find Pokemon with lowest level	
				case 4: 
					//if you found a pokemon
						cout<<"The pokemon with the lowest level is:"<<"GIMME YOUR VALUE HERE"<<
						" who is level " << "GIMME YOUR VALUE HERE"<<endl;
					//else you should return cout<<"Not found\n";
					break;
				
				// Find Pokemon with highest level
				case 5: 
					//if you found a pokemon
						cout<<"The pokemon with the highest level is :"<<"GIMME YOUR VALUE HERE"<< 
						" who is level " << "GIMME YOUR VALUE HERE"<<endl;
					//else you should return cout<<"Not found\n";
					break;

				// Find Pokemon by name and show his informations	
				case 6: 
					cout<<"Find what:";
					cin>>name;
					//if you found a pokemon :
						cout<<"Pokemon found : "<< "GIMME YOUR VALUE HERE"<< " Level : "
						<< "GIMME YOUR VALUE HERE" << " Type : " << "GIMME YOUR VALUE HERE" << endl;
					
					//else you should return cout<<"Not found\n";
						
					
					break;

				// Show all Pokemon in rooster	
				case 7: 
					cout<<"All Pokemons in rooster:\n";
					printall(pfirst);
					break;

				// Quit Pokemon Rooster	
				case 8: 
					exit(0);
				default: 
					cout<<"Invalid choice\n";
					break;

			}
		} catch (int e) {
			cout << "An error occured. Please try again." << endl;
			cout << e << endl;
		}
		cout<<"Continue? (y/n):";
		cin>>continuePrompt;
	}
}

void Insert (std::string name,int lvl, std::string type, int pos){
	if(pos < 0){
		cout<<"invalid position\n";
		return;
	}
	ListElem * pokemon = new ListElem();
	pokemon->name = name;
	pokemon->level = lvl;
	pokemon->type = type;
	if (pfirst == NULL){
		pokemon->p_next = pokemon;
		pokemon->p_previous = pokemon;
		plast = pokemon;
		pfirst = pokemon;

	} else {
		ListElem * temp = pfirst;
		for(int i = 0;i<=pos;i++){
			temp = temp->p_next;
		}
		pokemon->p_next = temp;
		pokemon->p_previous = temp->p_previous;
		temp->p_previous->p_next = pokemon;
		temp->p_previous = pokemon;
		if (pokemon->p_next == pfirst){
			plast = pokemon;
		}  
		if (pokemon->p_previous == plast){
			pfirst = pokemon;
		}
	}
}


void printall(ListElem *L){
	int pos = 0;
	cout << "position | name | level | type\n";
	while(L != NULL){
		cout << pos << " | " << L->name << " | " << L->level << " | " << L->type << endl;
		pos++;
		L = L->p_next;
		if (plast == L){
			L = NULL;
		}
	}
}


int main(){
	showmenu();
	select();
	return 0;
}
