#include <vector>
#include "person.h"
 
 class Application
 {
 private:
 	vector<Person> vectPerson;
 	void afficherMenu();
 	char saisieDuChoix();
 	void realiserActionChoix(char leChoix);
 	void ajouterPerson();
 	void afficherAllPerson();
 	Person rechercherPerson();
 public:
 	void run();

 };