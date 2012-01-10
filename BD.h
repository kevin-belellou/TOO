#ifndef BD_H
#define BD_H

#include "Livre.h"

/**
 * Classe BD qui hérite de Livre 
 */
class BD : public Livre
{
    public:

        /**
         * Constructeur surchargé de BD
         * @param titre string
         * @param auteur string
         * @param editeur string
         * @param dessinateur
         */
        BD(string titre, string auteur, string editeur, string dessinateur);

        /**
         * Destructeur de BD
         */
        virtual ~BD();

        /**
         * Getteur de Dessinateur
         * @return _dessinateur
         */
        string getDessinateur() const;
        
        /**
         * Setteur de Dessinateur
         * @param val string
         */
        void setDessinateur(string val);

        /**
         * méthode permettant d'afficher l'objet BD
         */
        virtual string afficher() const;
    protected:
    private:
        string _dessinateur;
};

#endif // BD_H
