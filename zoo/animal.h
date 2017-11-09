#ifndef ANIMAL
	#define ANIMAL
#include <iostream>
using namespace std;

class Animal
{
private:
	string nom;
	string ddn;
	Animal* pere;
	Animal* mere;
public:
	static int nbAnimaux;
	virtual void display();
	Animal(string name, string datenaiss , Animal* father , Animal* mother );
	~Animal();
	static void displayNb();
	virtual void crier()=0;
};
#endif