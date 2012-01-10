#include <iostream>
#include <string>

#include "Bibliotheque.h"

using namespace std;

int main()
{
    Bibliotheque polo;
    Roman toto("L'oeil du golem", "Jonathan Stroud", "Albin Michel", "Fantastique");
	Roman titi("Les Fourmis", "Bernard Werber", "Albin Michel", "Policier");
    Roman tete("Le symbole perdu", "Dan Brown", "France Loisirs", "Aventure");
    Roman tata("Le rire du Cyclope", "Bernard Werber", "France Loisirs", "Policier");
    BD tutu("Tintin", "Herge", "Herge", "Aventure");


    polo.ajouter(&toto);
    polo.ajouter(&tutu);
    polo.ajouter(&titi);
    polo.ajouter(&tete);
    polo.afficher();
    
    
    cout<<endl;
    polo.tri("titre");
  	polo.recherche("Le symbole perdu");
  	cout<<endl;
  	polo.afficher();

    cout << endl;

    polo.supprimer(&tete);
    polo.afficher();
    polo.recherche("Le symbole perdu");

    return 0;
}
