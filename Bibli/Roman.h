#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"

/**
 * Classe Roman qui hérite de Livre
 */
class Roman : public Livre
{
    public:
        /**
         * Constructeur surchargé de Roman
         * @param titre string
         * @param auteur string
         * @param editeur string
         * @param type string
         */
        Roman(string titre, string auteur, string editeur, string type);

        /**
         * Destructeur virtuel de Roman
         */
        virtual ~Roman();

        /**
         * Getteur de Type
         * @return _type string
         */
        string getType() const;
        
        /**
         * Setteur de Type
         * @param val string
         */
        void setType(string val);

        /**
         * Méthode permettant d'afficher un objet de type Roman
         * @return string
         */
        virtual string afficher() const;
        
        /**
         * Méthode permettant d'ajouter l'objet dans la BDD
         */  
        virtual void ajout() const;
    private:
        string _type;
};

#endif // ROMAN_H
