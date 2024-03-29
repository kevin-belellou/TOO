#include "Bibliotheque.h"

// Constructeur Par d�faut
Bibliotheque::Bibliotheque()
{

}

// Destructeur
Bibliotheque::~Bibliotheque()
{

}

// M�thodes

/*
Cette m�thode permet d'ajouter un document dansla biblioth�que.
On ajoute dans le vecteur ainsi que dans le fichier "Bibli.txt" qui sert de Base de donn�es. Le fait d'ajouter dans un vecteur facilite le trie, la recherche, la supression etc... De plus cela �vite d'ouvrir et de fermer le fichier "Bibli.txt", ce qui permet une meilleur stabilit�.
*/
void Bibliotheque::ajouter(Document* doc)
{

	unsigned int i = 0;
	bool trouve = false;
	
		while ((!trouve) && (i < this->_bibli.size()) )
	{
		//Si on trouve on arr�te de chercher et on affiche.
		if(this->_bibli[i] == doc)

		{
			trouve = true;
			cout << "Votre Document existe d�ja dans la Bibliotheque."<< endl;
		}
		else
            i++;
	}
	if (!trouve)
	{
    	this->_bibli.push_back(doc);
		doc->ajout();	
		// On fait appel � la fonction ajout en utilisant le polymorphisme, permettant d'ajouter dans la BDD
	}

}


/*
Cette m�thode recherche et supprime le document envoy� en param�tre. Elle le supprime dans le vecteur, et ensuite on efface tout le contenu de la BDD et on recopie chaque �l�ment du vecteur dans le fichier.
*/
void Bibliotheque::supprimer(Document* doc)
{

	unsigned int i = 0;
	bool trouve = false;
	
	while ((!trouve) && (i < this->_bibli.size()) )
	{
	//Si on trouve on arr�te de chercher et on affiche.
		if(this->_bibli[i] == doc)
		{
			trouve = true;
			for (unsigned int j(i + 1); j < this->_bibli.size(); j++)
			{
	            this->_bibli[j - 1] = this->_bibli[j];
	        }
	        this->_bibli.pop_back();
		}
		else
	        i++;
	}
	if (!trouve)
	{
		cout << "Ce document n'est pas dans la bibliotheque." <<endl;
		
	}
    

	//On Ouvre le fichier en effa�ant le contenu, et on le ferme.
    ofstream fichier("Bibli.txt", ios::out | ios::trunc);
   	if(fichier)  // si l'ouverture a r�ussi
   	{     
   	fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur � l'ouverture !" << endl;
	
	//On ajoute pour chaque �l�ment du vecteur, le contenu dans la BDD
	for (unsigned int u(0); u < this->_bibli.size(); u++)
	{
       this->_bibli[u]->ajout();
	}
	   

}

/*

//Ceci est l'affichage lors de la premi�re version, quand on avait pas impl�ment� de BDD.

void Bibliotheque::afficher() const
{
    if (this->_bibli.size() != 0)
        for (unsigned int i(0); i < this->_bibli.size(); i++)
            cout << i << " : " << this->_bibli[i]->afficher() << endl;
}
*/

/*
On affiche tout le contenu de la BDD
*/
void Bibliotheque::afficher() const
{
	//On ouvre le fichier en lecture
	ifstream fichier("Bibli.txt", ios::in);
    if(fichier)  // si l'ouverture a r�ussi
    {
		string ligne;
		while(getline(fichier, ligne))
        {		
        		//On stock chaque ligne du fichier dans un string, que l'on affiche. Et ce jusqu'� la fin du fichier
                cout << ligne << endl;
        }     
     	fichier.close();  // on referme le fichier
    }
    else //On affiche si il y a eu une erreur d'ouverture.
     cerr << "Erreur � l'ouverture !" << endl;
}


/*
Cette m�thode recherhe dans le vecteur si le document existe.
Nul besoin de chercher dans le fichier, puisqu'il est � jour par rapport au vecteur.
*/
void Bibliotheque::recherche(string pSearch) const
{

	bool trouve = false;
	unsigned int i = 0;
	
	//Oncherche tant que le fichier n'est pas trouv�, ou qu'on ai parcouru tout le vecteur.
	while ((!trouve) && (i <= this->_bibli.size()) )
	{
		//Si on trouve on arr�te de chercher et on affiche.
		if(this->_bibli[i]->getTitre() == pSearch)

		{
			trouve = true;
			cout << "Votre Document existe dans la Bibliotheque, il est a la place " << i << " :" << endl;
			cout << "- " << this->_bibli[i]->afficher() << endl;
		}
		else
            i++;
	}
	//Si on ne trouve pas.
	if(!trouve)
		cout << "Votre document n'est pas dans la Bibliotheque" << endl;
}

/*
Cette m�thode tri le vecteur en fonction du type du tri (par Titre ou Auteur).
Une fois le vecteur tri�, on efface la BDD et on recopie chaque �l�ment du vecteur dans le fichier.
Pour le tri, on utilise un tri � bulle.
*/
void Bibliotheque::tri(string pTri)
{
	bool tab_en_ordre = false;
	bool deja_tri = true; 
	//Ce bool�en va permettre de savoir si le vecteur est d�j� tri�, �vitant de perdre du temps � le parcourir

	//On v�rifie que le choix du tri est valide
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
		        	//On compare les titres, et on les �changes si besoin
		            swap(this->_bibli[i], this->_bibli[i+1]);
		            tab_en_ordre = false;
		            deja_tri = false;
		        }
		    }
		    taille--;
		}
	} //Si le Tri est en fonction de l'auteur
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
		        	//On compare les auteurs, et on les �changes si besoin
		            swap(this->_bibli[i], this->_bibli[i+1]);
		            tab_en_ordre = false;
		            deja_tri = false;
		        }
		    }
		    taille--;
		}
	}
	else cout << "Votre choix de tri n'est pas valide, merci de choisir soit 'auteur' ou 'titre'. " << endl;

	//On affiche si la Biblioth�que � �t� tri� ou non
	if (deja_tri == false)
		cout << "Votre Bibliotheque a ete triee." << endl;
	else
        cout << "Votre Bibliotheque est deja triee" << endl;
	
	
	//On ouvre le fichier et on efface son contenu
	ofstream fichier("Bibli.txt", ios::out | ios::trunc);
   	if(fichier)  // si l'ouverture a r�ussi
   	{     
   	fichier.close();  // on referme le fichier
    }
    else
     cerr << "Erreur � l'ouverture !" << endl;
	
	//On recopie chaque �l�ment du vecteur dans la BDD
	for (unsigned int u(0); u < this->_bibli.size(); u++)
	{
       this->_bibli[u]->ajout();
	}
}
