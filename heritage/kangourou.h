#ifndef KANGOUROU
 #define KANGOUROU
#include "animal.h"
class Kangourou : public Animal
{
private: 
 static int nbKangourou;
public:
	static void displayNbKangourou();
	~Kangourou();
	Kangourou(string name, string datenaiss , Animal* father , Animal* mother );
	void display();
	void crier();
};
#endif