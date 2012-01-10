#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <vector>
#include "Roman.h"
#include "BD.h"
#include <fstream>
#include <typeinfo>


        /**
         * Classe Bibliotheque qui va permettre de stocker les objets de types Document
         */
class Bibliotheque
{
    public:

        /**
         * Constructeur par défaut Bibliotheque
         */
        Bibliotheque();

        /**
         * Destructeur
         */
        virtual ~Bibliotheque();

        /**
         * Méthode permettant d'ajouter un Document dans la Bibliotheque
         * @param doc pointeur de type Document
         */
        void ajouter(Document* doc);
        
        /**
         * Méthode permettant de supprimer un Document de la Bibiotheque
         * @param doc pointeur de type Document
         */
        void supprimer(Document* doc);
        
        /**
         * Méthode permettant d'afficher la Bibliotheque
         */
        void afficher() const;
        
        /**
         * Méthode permettant de rechercher un document dans la bibliotheque
         * @param pSearch string
         */
        void recherche(string pSearch) const;
        
        /**
         * Méthode permettant de trier le tableau (soit par titre, soit par auteur).
         * @param pTri string
         */
        void tri(string pTri);
    protected:
    private:
        vector<Document*> _bibli;
};

#endif // BIBLIOTHEQUE_H
