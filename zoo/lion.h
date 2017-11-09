#ifndef LION
 #define LION
#include "animal.h"
class Lion : public Animal
{
private: 
	int tailleCriniere;
	static int nbLion;
public:
	static void displayNbLion();
	Lion(string name, string datenaiss , Animal* father , Animal* mother , int laTailleCiniere);
	void display();
	void crier();
	~Lion();
};
#endif