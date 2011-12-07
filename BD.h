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

        // Méthodes
        string getDessinateur();
        void setDessinateur(string val);

        virtual string afficher();
    protected:
    private:
        string _dessinateur;
};

#endif // BD_H
