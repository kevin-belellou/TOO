#include "Livre.h"

// Constructeur
Livre::Livre(string titre, string auteur, string editeur)
    : _titre(titre), _auteur(auteur), _editeur(editeur)
{

}

// Destructeur
Livre::~Livre()
{

}

// Méthodes
string Livre::get_titre()
{
    return this->_titre;
}

void Livre::set_titre(string val)
{
    this->_titre = val;
}

string Livre::get_auteur()
{
    return this->_auteur;
}

void Livre::set_auteur(string val)
{
    this->_auteur = val;
}

string Livre::get_editeur()
{
    return this->_editeur;
}

void Livre::set_editeur(string val)
{
    this->_editeur = val;
}

void Livre::afficher()
{
    cout << this->_titre << ", " << this->_auteur << ", " << this->_editeur << endl;
}
