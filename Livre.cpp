#include "Livre.h"

// Constructeur
Livre::Livre(string titre, string auteur, string editeur)
    : Document(titre, auteur), _editeur(editeur)
{

}

// Destructeur
Livre::~Livre()
{

}

// M�thodes
string Livre::getEditeur() const
{
    return this->_editeur;
}

void Livre::setEditeur(string val)
{
    this->_editeur = val;
}

string Livre::afficher() const
{
    return this->Document::afficher() + ", " + this->_editeur;
}
