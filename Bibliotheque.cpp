#include "Bibliotheque.h"

// Constructeur
Bibliotheque::Bibliotheque()
{

}

// Destructeur
Bibliotheque::~Bibliotheque()
{

}

// Méthodes
void Bibliotheque::ajouter(Document* doc)
{
    for (int i(0); i < this->_bibli.size(); i++)
        if (this->_bibli[i] == doc)
        {
            cout << "Ce document est deja dans la bibliotheque !" <<endl;
            return;
        }
        this->_bibli.push_back(doc);
}

void Bibliotheque::supprimer(Document* doc)
{
    for (int i(0); i < this->_bibli.size(); i++)
        if (this->_bibli[i] == doc)
        {
            for (int j(i + 1); j < this->_bibli.size(); j++)
                this->_bibli[j - 1] = this->_bibli[j];
            this->_bibli.pop_back();
            return;
        }
    cout << "Ce document n'est pas dans la bibliotheque !" <<endl;
}

void Bibliotheque::afficher()
{
    if (this->_bibli.size() != 0)
        for (int i(0); i < this->_bibli.size(); i++)
            cout << i << " : " << _bibli[i]->afficher() << endl;
}
