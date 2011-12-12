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

// M�thodes
string Roman::getType() const
{
    return this->_type;
}

void Roman::setType(string val)
{
    this->_type = val;
}

string Roman::afficher() const
{
    return this->Livre::afficher() + ", " + this->_type;
}
