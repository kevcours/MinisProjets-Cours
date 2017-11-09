#include "kangourou.h"

int Kangourou::nbKangourou=0;

Kangourou::Kangourou(string name, string datenaiss , Animal* father , Animal* mother) 
		:Animal(name,datenaiss,father ,mother )
{
	nbKangourou++;
}

void Kangourou::crier()
{
	cout<<"Le kangourou siffle"<<endl;
}

Kangourou::~Kangourou()
{
	nbKangourou--;
}
void Kangourou::displayNbKangourou()
{
	cout<<"le nombre de Kangourou est de : "<<nbKangourou<<endl;
}
void Kangourou::display()
{
	cout<<"*******************BONJOUR*****************"<<endl;
	cout<<"********** Je suis un KANGOUROU ***********"<<endl;
	Animal::display();
}