#include "Roman.h"

// Constructeur
Roman::Roman(string titre, string auteur, string editeur, string type)
    : Livre(titre, auteur, editeur), _type(type)
{

}

// Destructeur
Roman::~Roman()
{

}

// Méthodes
string Roman::getType()
{
    return this->_type;
}

void Roman::setType(string val)
{
    this->_type = val;
}

string Roman::afficher()
{
    return this->Livre::afficher() + ", " + this->_type;
}
