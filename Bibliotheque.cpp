#include "Bibliotheque.h"

// Constructeur
Bibliotheque::Bibliotheque()
{

}

// Destructeur
Bibliotheque::~Bibliotheque()
{

}

// Méthodes

void Bibliotheque::ajouter(Document* doc)
{
<<<<<<< HEAD
    for (unsigned int i(0); i < this->_bibli.size(); i++)
        if (this->_bibli[i] == doc)
        {
            cout << "Ce document est deja dans la bibliotheque !" << endl;
            return;
        }
        this->_bibli.push_back(doc);
=======

		for (unsigned int i(0); i < this->_bibli.size(); i++)
		{
            if (this->_bibli[i] == doc)
		    {
		        cout << "Ce document est deja dans la bibliotheque !" <<endl;
		        return;
		    }	    
		}
		
		this->_bibli.push_back(doc);
		doc->ajout();	
>>>>>>> 9386edaf9609855f6e5b90e09d67df965971aa38
}

void Bibliotheque::supprimer(Document* doc)
{
    for (unsigned int i(0); i < this->_bibli.size(); i++)
    {
       if (this->_bibli[i] == doc)
        {
            for (unsigned int j(i + 1); j < this->_bibli.size(); j++)
                this->_bibli[j - 1] = this->_bibli[j];
            this->_bibli.pop_back();
            break;
        }
<<<<<<< HEAD
    cout << "Ce document n'est pas dans la bibliotheque !" << endl;
=======
    	else 
    		cout << "Ce document n'est pas dans la bibliotheque !" <<endl;
    }
    


    ofstream fichier("Bibli.txt", ios::out | ios::trunc);
   	if(fichier)  // si l'ouverture a réussi
   	{     
   	fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
	
	for (unsigned int u(0); u < this->_bibli.size(); u++)
	{
       this->_bibli[u]->ajout();
	}
	   
>>>>>>> 9386edaf9609855f6e5b90e09d67df965971aa38
}

/*
void Bibliotheque::afficher() const
{
    if (this->_bibli.size() != 0)
        for (unsigned int i(0); i < this->_bibli.size(); i++)
            cout << i << " : " << this->_bibli[i]->afficher() << endl;
}
*/
void Bibliotheque::afficher() const
{
	ifstream fichier("Bibli.txt", ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
		string ligne;
		while(getline(fichier, ligne))
        {
                cout << ligne << endl;
        }     
     	fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
}


void Bibliotheque::recherche(string pSearch) const
{
	bool trouve = false;
	unsigned int i = 0;

	while ((!trouve) && (i <= this->_bibli.size()) )
	{
		if(this->_bibli[i]->getTitre() == pSearch)
		{
			trouve = true;
			cout << "Votre Document existe dans la Bibliotheque, il est a la place " << i << " :" << endl;
			cout << "- " << this->_bibli[i]->afficher() << endl;
		}
		else
            i++;
	}

	if(!trouve)
		cout << "Votre document n'est pas dans la Bibliotheque" << endl;
}


void Bibliotheque::tri(string pTri)
{
	bool tab_en_ordre = false;
	bool deja_tri = true;

    if(pTri == "titre")
    {
		unsigned int taille = this->_bibli.size();

		while(!tab_en_ordre)
		{
		    tab_en_ordre = true;

		    for(unsigned int i=0 ; i < taille-1 ; i++)
		    {
		        if(this->_bibli[i]->getTitre() > this->_bibli[i+1]->getTitre())
		        {
		            swap(this->_bibli[i], this->_bibli[i+1]);
		            tab_en_ordre = false;
		            deja_tri = false;
		        }
		    }
		    taille--;
		}
	}
	else if (pTri == "auteur")
	{
		unsigned int taille = _bibli.size();

		while(!tab_en_ordre)
		{
		    tab_en_ordre = true;

		    for(unsigned int i=0 ; i < taille-1 ; i++)
		    {
		        if(this->_bibli[i]->getAuteur() > this->_bibli[i+1]->getAuteur())
		        {
		            swap(this->_bibli[i], this->_bibli[i+1]);
		            tab_en_ordre = false;
		            deja_tri = false;
		        }
		    }
		    taille--;
		}
	}
	else cout << "Votre choix de tri n'est pas valide, merci de choisir soit 'auteur' ou 'titre'. " << endl;

<<<<<<< HEAD
	if (deja_tri == false)
		cout << "Votre Bibliotheque a ete triee." << endl;
	else
        cout << "Votre Bibliotheque est deja triee" << endl;
=======
	if (deja_tri==false)
	{
		cout<<"Votre Bibliotheque à été Trié."<<endl;
	}
	else cout<<"Votre Bibliotheque est déja Trié"<<endl;
	
	
	ofstream fichier("Bibli.txt", ios::out | ios::trunc);
   	if(fichier)  // si l'ouverture a réussi
   	{     
   	fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
	
	for (unsigned int u(0); u < this->_bibli.size(); u++)
	{
       this->_bibli[u]->ajout();
	}
>>>>>>> 9386edaf9609855f6e5b90e09d67df965971aa38
}
