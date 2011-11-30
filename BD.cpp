#include "BD.h"

// Constructeur
BD::BD(string titre, string auteur, string editeur, string dessinateur)
    : Livre(titre, auteur, editeur), _dessinateur(dessinateur)
{

}

// Destructeur
BD::~BD()
{

}

// Méthodes
string BD::getDessinateur()
{
    return this->_dessinateur;
}

void BD::setDessinateur(string val)
{
    this->_dessinateur = val;
}

string BD::afficher()
{
    return this->Livre::afficher() + ", " + this->_dessinateur;
}
