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

// Méthodes
string Livre::getEditeur() const
{
    return this->_editeur;
}

void Livre::setEditeur(string val)
{
    this->_editeur = val;
}

/*
La méthode afficher est polymorphe, on appel donc la méthode de la classe parente et on ajoute ce que l'on veut afficher en plus.
*/
string Livre::afficher() const
{
    return this->Document::afficher() + ", " + this->_editeur;
}

/*
Le but de cette méthode est d'ajouter le document dans la BDD. Pour cela on ouvre le fichier en écriture,
et on écrit les attributs de la classe. Une fois terminé on ferme le fichier.
*/
void Livre::ajout() const
{
	//On ouvre en écriture
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a réussi
    {
    fichier<<this->_auteur<<", "<<this->_titre<<", "<<this->_editeur<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
}
