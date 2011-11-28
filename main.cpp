#include <iostream>
#include <string>

#include "Bibliotheque.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Bibliotheque polo;
    Roman toto("L'oeil du golem", "Jonathan Stroud", "Albin Michel", "Angleterre", "Helene Collon");
    Roman tutu("Le symbole perdu", "Dan Brown", "France Loisirs", "Etats-Unis", "Dominique Defert et Alexandre Boldrini");

    polo.ajouter(&toto);
    polo.ajouter(&tutu);
    polo.afficher();

    cout << endl;

    polo.supprimer(0);
    polo.afficher();

    return 0;
}
