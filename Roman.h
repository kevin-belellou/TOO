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
        Roman(string titre, string auteur, string editeur, string type);

        // Destructeur
        virtual ~Roman();

        // M�thodes
        string getType();
        void setType(string val);

        virtual string afficher();
    protected:
    private:
        string _type;
};

#endif // ROMAN_H
