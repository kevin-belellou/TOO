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

void Bibliotheque::afficher()
{
    if (this->_bibli.size() != 0)
        for (int i(0); i < this->_bibli.size(); ++i)
        {
            _bibli[i]->afficher();
        }

}
