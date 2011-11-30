#include <iostream>
#include <string>

#include "Bibliotheque.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Bibliotheque polo;
    Roman toto("L'oeil du golem", "Jonathan Stroud", "Albin Michel", "Fantastique");
    Roman tutu("Le symbole perdu", "Dan Brown", "France Loisirs", "Aventure");
    Roman tata("Le rire du Cyclope", "Bernard Werber", "France Loisirs", "Policier");

    polo.ajouter(&toto);
    polo.ajouter(&tutu);
    polo.ajouter(&tata);
    polo.afficher();

    cout << endl;

    polo.supprimer(1);
    polo.afficher();

    return 0;
}
