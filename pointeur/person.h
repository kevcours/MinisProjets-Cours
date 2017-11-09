using namespace std;
#include <iostream>
class Person
{
private:
	string name;
	string surname;
	string birthdate;
public:
	string getName();
	string getSurname();
	string getBirthdate();
	void setName( string theName);
	void setSurname( string theSurname);
	void setBirthdate ( string theBirthdate);
	void display();
	void input();
	Person(string theName, string theSurname, string theBirthdate);
	Person(){};
	
};