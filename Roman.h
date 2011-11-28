#ifndef ROMAN_H
#define ROMAN_H

#include <iostream>
#include <string>
#include "Livre.h"

using namespace std;

class Roman : public Livre
{
    public:
        // Constructeur
        Roman(string titre, string auteur, string editeur, string nationalite, string traducteur = "");

        // Destructeur
        virtual ~Roman();

        // Méthodes
        string get_nationalite();
        void set_nationalite(string val);
        string get_traducteur();
        void set_traducteur(string val);

        virtual void afficher();
    protected:
        string _nationalite;
        string _traducteur;
    private:
};

#endif // ROMAN_H
