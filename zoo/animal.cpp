#include "animal.h"
int Animal::nbAnimaux=0;

Animal::Animal(string name, string datenaiss , Animal* father , Animal* mother )
{
	nom=name;
	ddn=datenaiss;
	pere=father;
	mere=mother;
	nbAnimaux++;

}
void Animal::displayNb()
{
	cout<<"Le nombre d'animaux est de : "<<nbAnimaux<<endl;
}

void Animal::display()
{
	cout<<"Voici "<<nom<<" qui est né le "<<ddn<<endl;
}
Animal::~Animal()
{
	nbAnimaux--;
}
