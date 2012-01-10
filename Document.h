#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>
#include <fstream>
//#include <typeinfo> // EN TEST

using namespace std;

/**
 * Classe abstraite Document
 */
class Document
{
    public:
        /**
         * Constructeur surchargé
         * @param titre string
         * @param auteur string
         */
        Document(string titre, string auteur);

        /**
         * Destructeur virtuel pur
         */
        virtual ~Document() = 0;

        /**
         * Getteur de titre
         * @return _titre
         */
        string getTitre() const;

        /**
         * Setteur de Titre
         * @param val string
         */
        void setTitre(string val);

        /**
         * Getteur de Auteur
         * @return _auteur
         */
        string getAuteur() const;

        /**
         * Setteur d'Auteur
         * @param val
         */
        void setAuteur(string val);

        /**
         * Méthode permettant d'afficher l'objet de type Document
         * @return string
         */
        virtual string afficher() const;

        /**
         * Méthode permettant d'ajouter l'objet dans la BDD
         */        
        virtual void ajout() const;
    protected:
        string _titre;
        string _auteur;
};

#endif // DOCUMENT_H
