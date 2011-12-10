#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <string>
#include "Document.h"

using namespace std;

class Livre : public Document
{
    public:
        // Constructeur
        Livre(string titre, string auteur, string editeur);

        // Destructeur
        virtual ~Livre();

        // Méthodes
        string getEditeur();
        void setEditeur(string val);

        virtual string afficher();
    protected:
    private:
        string _editeur;
};

#endif // LIVRE_H
