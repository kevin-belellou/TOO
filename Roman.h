#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"

class Roman : public Livre
{
    public:
        // Constructeur
        Roman(string titre, string auteur, string editeur, string type);

        // Destructeur
        virtual ~Roman();

        // M�thodes
        string getType() const;
        void setType(string val);

        virtual string afficher() const;
    protected:
    private:
        string _type;
};

#endif // ROMAN_H
