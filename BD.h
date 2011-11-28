#ifndef BD_H
#define BD_H

#include <iostream>
#include <string>
#include "Livre.h"

using namespace std;

class BD : public Livre
{
    public:
        // Constructeur
        BD(string titre, string auteur, string editeur, string dessinateur);

        // Destructeur
        virtual ~BD();

        // Méthodes
        string get_dessinateur();
        void set_dessinateur(string val);

        virtual void afficher();
    protected:
        string _dessinateur;
    private:
};

#endif // BD_H
