#include <iostream>
using namespace std;

int main()
{
	int nb1;
	int nb2;
	cout<<"Saisir le premier nombre: "<<endl;
	cin>>nb1;
	cout<<"Saisir le deuxieme nombre: "<<endl;
	cin>>nb2;
	int *pLePlusPetit;
	int *pLePlusGrand;
	if (nb1<nb2)
	{
		pLePlusPetit= &nb1;
		pLePlusGrand= &nb2;
	} 
	else
	{
		pLePlusPetit= &nb2;
		pLePlusGrand= &nb1;
	}
	cout<<" Le plus grand nombre est : "<<*pLePlusGrand<<endl
		<<" Le plus petit nombre est : "<<*pLePlusPetit<<endl
		<<" l'adresse du premier nombre: "<<&nb1<<endl
		<<"l'adresse du deuxieme nombre: "<<&nb2<<endl;


}