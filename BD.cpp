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

// M�thodes
string BD::getDessinateur() const
{
    return this->_dessinateur;
}

void BD::setDessinateur(string val)
{
    this->_dessinateur = val;
}

/*
La m�thode afficher est polymorphe, on appel donc la m�thode de la classe parente et on ajoute ce que l'on veut afficher en plus.
*/
string BD::afficher() const
{
    return this->Livre::afficher() + ", " + this->_dessinateur;
}

/*
Le but de cette m�thode est d'ajouter le document dans la BDD. Pour cela on ouvre le fichier en �criture,
et on �crit les attributs de la classe. Une fois termin� on ferme le fichier.
*/
void BD::ajout() const
{
	//On ouvre le fichier en �criture
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a r�ussi
    {
    fichier<<this->_auteur<<", "<<this->_titre<<", "<<this->_editeur<<", "<<this->_dessinateur<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur � l'ouverture !" << endl;
}
