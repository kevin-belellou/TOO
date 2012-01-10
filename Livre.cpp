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

string Livre::afficher() const
{
    return this->Document::afficher() + ", " + this->_editeur;
}

void Livre::ajout() const
{
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a réussi
    {
    fichier<<this->_auteur<<", "<<this->_titre<<", "<<this->_editeur<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
}
