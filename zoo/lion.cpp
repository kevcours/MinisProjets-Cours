#include "lion.h"
int Lion::nbLion=0;
Lion::Lion(string name, string datenaiss , Animal* father , Animal* mother , int laTailleCiniere)
		:Animal(name,datenaiss,father ,mother )
{
	tailleCriniere=laTailleCiniere;
	nbLion++;
}
void Lion::display()
{
	cout<<"*******************BONJOUR*****************"<<endl;
	cout<<"**************Je suis un LION **************"<<endl;
	Animal::display();
	cout<<"Taille de la criniere : "<<tailleCriniere<<endl;
}
void Lion::crier()
{
	cout<<"I'm THE LION KING ROOOOOOOAAAAAAR !"<<endl;
}
void Lion::displayNbLion()
{
	cout<<"le nombre de Lion est de : "<<nbLion<<endl;
}
Lion::~Lion()
{
	nbLion--;
}