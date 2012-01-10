#include "Document.h"

// Constructeur
Document::Document(string titre, string auteur)
    : _titre(titre), _auteur(auteur)
{

}

// Destructeur
Document::~Document()
{

}

// Méthode
string Document::getTitre() const
{
    return this->_titre;
}

void Document::setTitre(string val)
{
    this->_titre = val;
}

string Document::getAuteur() const
{
    return this->_auteur;
}

void Document::setAuteur(string val)
{
    this->_auteur = val;
}

string Document::afficher() const
{
    return this->_titre + ", " + this->_auteur;
}

void Document::ajout() const
{
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a réussi
    {
    
    fichier<<this->_auteur<<" "<<this->_titre<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
}
