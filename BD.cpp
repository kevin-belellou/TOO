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

string BD::afficher() const
{
    return this->Livre::afficher() + ", " + this->_dessinateur;
}

void BD::ajout() const
{
	ofstream fichier("Bibli.txt", ios::out | ios::app);
    if(fichier)  // si l'ouverture a r�ussi
    {
    fichier<<this->_auteur<<" "<<this->_titre<<" "<<this->_editeur<<" "<<this->_dessinateur<<endl;
    fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur � l'ouverture !" << endl;
}
