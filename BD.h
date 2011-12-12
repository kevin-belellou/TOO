#ifndef BD_H
#define BD_H

#include "Livre.h"

class BD : public Livre
{
    public:
        // Constructeur
        BD(string titre, string auteur, string editeur, string dessinateur);

        // Destructeur
        virtual ~BD();

        // M�thodes
        string getDessinateur() const;
        void setDessinateur(string val);

        virtual string afficher() const;
    protected:
    private:
        string _dessinateur;
};

#endif // BD_H
