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

/*
La m�thode afficher est polymorphe, on appel donc la m�thode de la classe parente et on ajoute ce que l'on veut afficher en plus.
*/
string Livre::afficher() const
{
    return this->Document::afficher() + ", " + this->_editeur;
}

/*
Le but de cette m�thode est d'ajouter le document dans la BDD. Pour cela on ouvre le fichier en �criture,
et on �crit les attributs de la classe. Une fois termin� on ferme le fichier.
*/
void Livre::ajout() const
{
	//On ouvre en �criture
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a r�ussi
    {
    fichier<<this->_auteur<<", "<<this->_titre<<", "<<this->_editeur<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur � l'ouverture !" << endl;
}
