#include "Roman.h"

// Constructeur
Roman::Roman(string titre, string auteur, string editeur, string nationalite, string traducteur)
    : Livre(titre, auteur, editeur), _nationalite(nationalite), _traducteur(traducteur)
{

}

// Destructeur
Roman::~Roman()
{

}

// Méthodes
string Roman::get_nationalite()
{
    return this->_nationalite;
}

void Roman::set_nationalite(string val)
{
    this->_nationalite = val;
}

string Roman::get_traducteur()
{
    return this->_traducteur;
}

void Roman::set_traducteur(string val)
{
    this->_traducteur = val;
}

void Roman::afficher()
{
    cout << this->_titre << ", " << this->_auteur << ", " << this->_editeur << ", " << this->_nationalite << ", " << this->_traducteur << endl;
}
