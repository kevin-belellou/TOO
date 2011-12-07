#include "Bibliotheque.h"

// Constructeur
Bibliotheque::Bibliotheque()
{

}

// Destructeur
Bibliotheque::~Bibliotheque()
{

}

// M�thodes
void Bibliotheque::ajouter(Document* doc)
{
    for (unsigned int i(0); i < this->_bibli.size(); i++)
        if (this->_bibli[i] == doc)
        {
            cout << "Ce document est deja dans la bibliotheque !" <<endl;
            return;
        }
        this->_bibli.push_back(doc);
}

void Bibliotheque::supprimer(Document* doc)
{
    for (unsigned int i(0); i < this->_bibli.size(); i++)
        if (this->_bibli[i] == doc)
        {
            for (unsigned int j(i + 1); j < this->_bibli.size(); j++)
                this->_bibli[j - 1] = this->_bibli[j];
            this->_bibli.pop_back();
            return;
        }
    cout << "Ce document n'est pas dans la bibliotheque !" <<endl;
}

void Bibliotheque::afficher() const
{
    if (this->_bibli.size() != 0)
        for (unsigned int i(0); i < this->_bibli.size(); i++)
            cout << i << " : " << _bibli[i]->afficher() << endl;
}

Bibliotheque Bibliotheque::trier(string param, int sens)
{
    Bibliotheque res;
    return res;
}
