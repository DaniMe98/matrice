#include <iostream>
#include "matrice.h"

using namespace std;

int main(){
	int x=5;
	int z=5;
	matrice test(x,z),traspos(x,z);
	
	tipoelem numero=5.2;
	tipoelem numero1=7.3;
	
	test.scriviMatrice(4,2,numero);
	test.scriviMatrice(1,4,numero1);
	test.scriviMatrice(3,2,numero+5);
	test.scriviMatrice(4,0,numero1+78);
	test.scriviMatrice(2,1,numero+9.2);
	test.scriviMatrice(0,0,numero1*8);
	test.scriviMatrice(0,3,numero*9.2);
	
	for(int j=0; j<x; j++){	
		for(int i=0; i<z; i++){
			cout<<test.leggiMatrice(j,i)<<" ";
				}
				cout<<endl;
	}
	cout<<endl;
	for(int j=0; j<x; j++){	
		for(int i=0; i<z; i++){
			cout<<traspos.leggiMatrice(j,i)<<" ";
				}
				cout<<endl;
	}
	cout<<endl;
	traspos=test.trasposta();
	traspos.stampa();
	
	double scalare=2.5;
	cout<<endl;
	
	test.prodottoScalare(scalare);
	test.stampa();
	
	cout<<endl;
	
	matrice R(6,x);
	R.random();
	R.stampa();
	
	cout<<endl;
	
	matrice P(x,5);
	
	P=test.prodotto(R);
	P.stampa();
	
	return 0;
}
