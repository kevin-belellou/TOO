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
    this->_bibli.push_back(doc);
}

void Bibliotheque::supprimer(int i)
{
    if (i >= 0 && i < this->_bibli.size())
        for (int j(i + 1); j < this->_bibli.size(); j++)
            this->_bibli[j - 1] = this->_bibli[j];
    this->_bibli.pop_back();
}

void Bibliotheque::afficher()
{
    if (this->_bibli.size() != 0)
        for (int i(0); i < this->_bibli.size(); i++)
        {
            cout << i << " : ";
            _bibli[i]->afficher();
        }

}
