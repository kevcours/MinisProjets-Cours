#include "kangourou.h"
#include "lion.h"
#include <vector>

int main()
{
	vector<Animal*> vectMesAnimaux;
	vectMesAnimaux.push_back(new Kangourou ("Kangourex", "01/01/2001", NULL ,NULL));
	vectMesAnimaux.push_back(new Kangourou ("Kangourette", "02/02/2002", NULL ,NULL));
	//Animal buse("Buse", "03/03/2003", NULL ,NULL);
	vectMesAnimaux.push_back(new Lion ("Symba","04/04/2004",NULL , NULL,1));
	vectMesAnimaux.push_back(new Lion ("Nahla","05/05/2005",NULL , NULL,0));
	Animal::displayNb();
	Kangourou::displayNbKangourou();
	Lion::displayNbLion();
	int nbAnimaux = Animal::nbAnimaux;
	for(int i =0 ; i<nbAnimaux ; i++)
	{
		vectMesAnimaux[i]->display();
		vectMesAnimaux[i]->crier();
	}
}