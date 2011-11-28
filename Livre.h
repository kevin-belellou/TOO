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
        string get_titre();
        void set_titre(string val);
        string get_auteur();
        void set_auteur(string val);
        string get_editeur();
        void set_editeur(string val);

        virtual void afficher();
    protected:
        string _titre;
        string _auteur;
        string _editeur;
    private:
};

#endif // LIVRE_H
