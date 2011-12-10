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
string Document::getTitre()
{
    return this->_titre;
}

void Document::setTitre(string val)
{
    this->_titre = val;
}

string Document::getAuteur()
{
    return this->_auteur;
}

void Document::setAuteur(string val)
{
    this->_auteur = val;
}

string Document::afficher()
{
    return this->_titre + ", " + this->_auteur;
}
