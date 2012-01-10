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

/*
La m�thode afficher est polymorphe, on appel donc la m�thode de la classe parente et on ajoute ce que l'on veut afficher en plus.
*/
string Roman::afficher() const
{
    return this->Livre::afficher() + ", " + this->_type;
}

void Roman::ajout() const
{
	//On ouvre le fichier en �criture
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a r�ussi
    {
    fichier<<this->_auteur<<", "<<this->_titre<<", "<<this->_editeur<<", "<<this->_type<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur � l'ouverture !" << endl;
}
