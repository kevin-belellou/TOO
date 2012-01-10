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

void Roman::ajout() const
{
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a réussi
    {
    fichier<<this->_auteur<<", "<<this->_titre<<", "<<this->_editeur<<", "<<this->_type<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
}
