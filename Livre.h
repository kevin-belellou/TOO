#ifndef LIVRE_H
#define LIVRE_H

#include "Document.h"

/**
 * Classe Livre qui hérite de Document
 */
class Livre : public Document
{
    public:
        /**
         * Constructeur surchargé de Livre
         * @param titre string
         * @param auteur string
         * @param editeur string
         */
        Livre(string titre, string auteur, string editeur);

        /**
         * Destructeur virtuel de Livre
         */
        virtual ~Livre();

        /**
         * Setteur de Editeur
         * @return string
         */
        string getEditeur() const;
        void setEditeur(string val);

        /**
         * Méthode permettant d'afficher l'objet de type Document
         * @return string
         */
        virtual string afficher() const;
        virtual void ajout() const;
    protected:
        string _editeur;
};

#endif // LIVRE_H
