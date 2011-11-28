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
string BD::get_dessinateur()
{
    return this->_dessinateur;
}

void BD::set_dessinateur(string val)
{
    this->_dessinateur = val;
}

void BD::afficher()
{
    cout << this->_titre << ", " << this->_auteur << ", " << this->_editeur << ", " << this->_dessinateur << endl;
}
