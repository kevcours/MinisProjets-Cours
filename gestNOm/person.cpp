#include "person.h"

string Person::getName()
{
	return name;
}

string Person::getSurname()
{
	return surname;
}

string Person::getBirthdate()
{
	return birthdate;
}

void Person::setName( string theName)
{
	name=theName;
}

void Person::setSurname( string theSurname)
{
	surname=theSurname;
}

void Person::setBirthdate( string theBirthdate)
{
	birthdate=theBirthdate;
}
void Person::display()
{
	cout<<"Nom: "<< name<<endl
		<<"Prénom: "<<surname<<endl
		<<"Date de naissance: "<<birthdate<<endl<<endl;

}
void Person::input()
{
	cout<<"Votre prénom? ";
	getline(cin,name);
	cout<<"Votre nom? ";
	getline(cin,surname);
	cout<<"votre date de naissance? ";
	getline(cin,birthdate);
	cout<<endl<<endl; 
}
Person::Person( string theName, string theSurname, string theBirthdate )
{
	name=theName;
	surname=theSurname;
	birthdate=theBirthdate;
}