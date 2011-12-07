#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <typeinfo>
using namespace std;

class Document
{
    public:
        // Constructeur
        Document(string titre, string auteur);

        // Destructeur (virtuel pur)
        virtual ~Document() = 0;

        // Méthode
        string getTitre();
        void setTitre(string val);
        string getAuteur();
        void setAuteur(string val);

        virtual string afficher();
    protected:
    private:
        string _titre;
        string _auteur;
};

#endif // DOCUMENT_H
