#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <iostream>
#include <vector>
#include "Roman.h"
#include "BD.h"

class Bibliotheque
{
    public:
        // Constructeur
        Bibliotheque();

        // Destructeur
        virtual ~Bibliotheque();

        // Méthodes
        void ajouter(Document* doc);
        void supprimer(Document* doc);
        void afficher() const;

        // Méthodes en test (ne pas prendre en compte)
        Bibliotheque trier(string param, int sens);
    protected:
    private:
        vector<Document*> _bibli;
};

#endif // BIBLIOTHEQUE_H
