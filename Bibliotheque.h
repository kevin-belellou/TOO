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

        // M�thodes
        void ajouter(Document* doc);
        void supprimer(Document* doc);
        void afficher();
    protected:
    private:
        vector<Document*> _bibli;
};

#endif // BIBLIOTHEQUE_H
