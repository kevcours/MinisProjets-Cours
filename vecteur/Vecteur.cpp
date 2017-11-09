#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector <int> vectQuantite;
	
	vectQuantite.push_back(6);
	vectQuantite.push_back(12);
	vectQuantite.push_back(24);
	

	for (int nb=0 ; nb< vectQuantite.size() ; nb++)
	{
		cout<<vectQuantite[nb]<<endl;
		cout<<vectQuantite.at(nb)<<endl;
	}

}