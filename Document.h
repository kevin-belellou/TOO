#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
using namespace std;

class Document
{
    public:
        // Constructeur
        Document();

        // Destructeur (virtuel pur)
        virtual ~Document() = 0;

        // Méthode (virtuelle pure)
        virtual void afficher();
    protected:
    private:
};

#endif // DOCUMENT_H
