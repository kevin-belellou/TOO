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

//On retourne les attributs de la classe pour pouvoir les afficher ensuite (par une fonction cout)
string Document::afficher() const
{
    return this->_titre + ", " + this->_auteur;
}

/*
Le but de cette méthode est d'ajouter le document dans la BDD. Pour cela on ouvre le fichier en écriture,
et on écrit les attributs de la classe. Une fois terminé on ferme le fichier.
*/
void Document::ajout() const
{
	//On ouvre en ecriture
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a réussi
    {
    
    //On écrit dans le fichier
    fichier<<this->_auteur<<", "<<this->_titre<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
}
