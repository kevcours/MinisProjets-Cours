#include "application.h"

void Application::run()
{       //executable de l'appli
		char sonChoix;
		do
		{
			afficherMenu();
			sonChoix=saisieDuChoix();
			realiserActionChoix(sonChoix);
		}
		while (!(sonChoix=='q'));
}

void Application::afficherMenu()                            //Afficher le menue
{
	int nbCase=vectPerson.size();
	if (nbCase==0)
	{
		cout<<"Que voulais vous faire : (+ pour ajouter) (q pour quitter)"<<endl;
	}
	else
	{
		cout<<" Que voulez vous faire : ( + pour ajouter) (r pour rechercher ) (a pour afficher toute les personnes)"
			<<"(q pour quitter)"<<endl;
	}
}

char Application::saisieDuChoix()                           //Enregistrer le choix dans une variable
{
	char leChoix;
	cin>>leChoix;
	cin.ignore(1);
	int nbCase=vectPerson.size();
	if (nbCase==0)
	{
		while(!(leChoix=='+' or leChoix=='q' or leChoix=='Q'))
		{
			cout<<"Erreur lors du choix veuiller recommencer: "<<endl;
			afficherMenu();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	else
	{
		while(!(leChoix=='+' or leChoix=='r' or leChoix=='R' or leChoix=='a' or leChoix=='A' or leChoix=='q' or leChoix=='Q'))
		{
			cout<<"Erreur lors du choix veuiller recommencer: "<<endl;
			afficherMenu();
			cin>>leChoix;
			cin.ignore(1);
		};
	}
	return leChoix;
}

void Application::ajouterPerson()
{
	Person newPersonne;
	newPersonne.input();
	vectPerson.push_back(newPersonne);
	
	
}

void Application::afficherAllPerson()
{
	int nbCase=vectPerson.size();
	if(nbCase == 0)
	{
		cout<<"Personne d'enregistrer ! "<<endl;
	}
	else
	{
		for (int noCase=0 ; noCase<nbCase; noCase++)
		{
	 		vectPerson[noCase].display();
		}
	}
}

Person Application::rechercherPerson()
{
	Person nobody("null","null","0");
	int nbCase=vectPerson.size();
	string nomRechercher;
	string prenomRechercher;
	cout<<"Nom a chercher: ";
	getline(cin,nomRechercher);
	cout<<"Prenom a chercher: ";
	getline(cin,prenomRechercher);
	cout<<endl;
	for ( int nbPerson=0 ; nbPerson<nbCase; nbPerson++)
	{
	
		if ((vectPerson[nbPerson].getName()==prenomRechercher) and (vectPerson[nbPerson].getSurname()==nomRechercher))
		{
			return vectPerson[nbPerson];
			cout<<endl<<endl;
		}
	}
	return nobody;
}

void Application::realiserActionChoix(char leChoix)
{
	int nbCase=vectPerson.size();
	if (nbCase==0)
	{
		switch (leChoix)
		{
			case '+':
			{
				ajouterPerson();
				break;
			}
		}
	}
	else
	{
		switch (leChoix)
		{
			case '+':
			{
				ajouterPerson();
				break;
			}
			case 'r':
			{
				Person wanted;
				wanted=rechercherPerson();
				if (!(wanted.getName()=="null"))
				wanted.display();
				else
				{
					cout<<"Personne ne correspond aux critères."<<endl;
				}
				break;
			}
			case 'a':
			{
				afficherAllPerson();
				break;
			}
		}
	}

	
}



