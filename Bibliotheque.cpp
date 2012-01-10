#include "Bibliotheque.h"

// Constructeur Par défaut
Bibliotheque::Bibliotheque()
{

}

// Destructeur
Bibliotheque::~Bibliotheque()
{

}

// Méthodes

/*
Cette méthode permet d'ajouter un document dansla bibliothèque.
On ajoute dans le vecteur ainsi que dans le fichier "Bibli.txt" qui sert de Base de données. Le fait d'ajouter dans un vecteur facilite le trie, la recherche, la supression etc... De plus cela évite d'ouvrir et de fermer le fichier "Bibli.txt", ce qui permet une meilleur stabilité.
*/
void Bibliotheque::ajouter(Document* doc)
{

		for (unsigned int i(0); i < this->_bibli.size(); i++)
		{
            if (this->_bibli[i] == doc)
		    {
		        cout << "Ce document est deja dans la bibliotheque !" <<endl;
		        return;
		    }	    
		}
		
		this->_bibli.push_back(doc);
		doc->ajout();	// On fait appel à la fonction ajout en utilisant le polymorphisme, permettant d'ajouter dans la BDD
}


/*
Cette méthode recherche et supprime le document envoyé en paramètre. Elle le supprime dans le vecteur, et ensuite on efface tout le contenu de la BDD et on recopie chaque élément du vecteur dans le fichier.
*/
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
    	else 
    		cout << "Ce document n'est pas dans la bibliotheque !" <<endl;
    }
    

	//On Ouvre le fichier en effaçant le contenu, et on le ferme.
    ofstream fichier("Bibli.txt", ios::out | ios::trunc);
   	if(fichier)  // si l'ouverture a réussi
   	{     
   	fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur à l'ouverture !" << endl;
	
	//On ajoute pour chaque élément du vecteur, le contenu dans la BDD
	for (unsigned int u(0); u < this->_bibli.size(); u++)
	{
       this->_bibli[u]->ajout();
	}
	   
}

/*

//Ceci est l'affichage lors de la première version, quand on avait pas implémenté de BDD.

void Bibliotheque::afficher() const
{
    if (this->_bibli.size() != 0)
        for (unsigned int i(0); i < this->_bibli.size(); i++)
            cout << i << " : " << _bibli[i]->afficher() << endl;
}
*/

/*
On affiche tout le contenu de la BDD
*/
void Bibliotheque::afficher() const
{
	//On ouvre le fichier en lecture
	ifstream fichier("Bibli.txt", ios::in);
    if(fichier)  // si l'ouverture a réussi
    {
		string ligne;
		while(getline(fichier, ligne))
        {		
        		//On stock chaque ligne du fichier dans un string, que l'on affiche. Et ce jusqu'à la fin du fichier
                cout << ligne << endl;
        }     
     	fichier.close();  // on referme le fichier
    }
    else //On affiche si il y a eu une erreur d'ouverture.
     cerr << "Erreur à l'ouverture !" << endl;
}


/*
Cette méthode recherhe dans le vecteur si le document existe.
Nul besoin de chercher dans le fichier, puisqu'il est à jour par rapport au vecteur.
*/
void Bibliotheque::recherche(string pSearch) const
{
	bool trouve=false;
	unsigned int i=0;
	while ( (!trouve) && (i<=_bibli.size()) ) //Oncherche tant que le fichier n'est pas trouvé, ou qu'on ai parcouru tout le vecteur.
	{
		//Si on trouve on arrête de chercher et on affiche.
		if(_bibli[i]->getTitre()==pSearch)
		{
			trouve=true;
			cout<<"Votre Document existe dans la Bibliotheque, il est à la place " <<i <<" :"<<endl;
			cout<<"- "<<_bibli[i]->afficher()<<endl;
		}
		else i++;
	}
	//Si on ne trouve pas.
	if(!trouve)
	{
		cout<<"Votre document n'est pas dans la Bibliotheque"<<endl;
	}

}

/*
Cette méthode tri le vecteur en fonction du type du tri (par Titre ou Auteur).
*/
void Bibliotheque::tri(string pTri)
{
	bool tab_en_ordre = false;
	bool deja_tri = true;

    if(pTri=="titre")
    {
		unsigned int taille = _bibli.size();
		while(!tab_en_ordre)
		{
		    tab_en_ordre = true;
		    for(unsigned int i=0 ; i < taille-1 ; i++)
		    {
		        if(_bibli[i]->getTitre() > _bibli[i+1]->getTitre())
		        {
		            swap(_bibli[i],_bibli[i+1]);
		            tab_en_ordre = false;
		            deja_tri = false;
		        }
		    }
		    taille--;
		}

	}
	else if (pTri=="auteur")
	{
		unsigned int taille = _bibli.size();
		while(!tab_en_ordre)
		{
		    tab_en_ordre = true;
		    for(unsigned int i=0 ; i < taille-1 ; i++)
		    {
		        if(_bibli[i]->getAuteur() > _bibli[i+1]->getAuteur())
		        {
		            swap(_bibli[i],_bibli[i+1]);
		            tab_en_ordre = false;
		            deja_tri = false;
		        }
		    }
		    taille--;
		}
	}
	else cout<<"Votre choix de tri n'est pas valide, merci de choisir soit 'auteur' ou 'titre'. "<<endl;

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
}
