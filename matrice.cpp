#include "matrice.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

matrice::matrice(int x,int y){
	n_colonne=x;
	n_righe=y;
	
	elementi=new tipoelem*[n_righe];
	
	int i,j;
	
	for(i=0; i<n_righe; i++){
		elementi[i]=new tipoelem[n_colonne];
	}
	
	for(i=0; i<n_righe; i++){
		
			for(j=0; j<n_colonne; j++){
				
					elementi[i][j]=0;
			}
	}
	
}

matrice::matrice(const matrice &m){
	n_righe=m.n_righe;
	n_colonne=m.n_colonne;
	int i,j;
	elementi=new tipoelem*[n_righe];
		
		for (i=0; i<n_righe; i++){
			elementi[i]=new tipoelem[n_colonne];
		}
		
		for(i=0; i<n_righe; i++){
			
				for(j=0; j<n_colonne; j++){
					
						elementi[i][j]=m.elementi[i][j];
				}
		}
	
	
}

matrice::~matrice(){
	for(int j=0; j<n_colonne; j++){
		delete[] elementi[j];
	}
	delete [] elementi;
}

matrice &matrice::operator=(const matrice &m){
	int i,j;
	
		if(this==&m){
			return *this;
		}else{
			if(n_righe!=m.n_righe || n_colonne!=m.n_colonne){
				
				this->~matrice();
				n_righe=m.n_righe;
				n_colonne=m.n_colonne;
				
				elementi=new tipoelem*[n_righe];
				
				for(i=0; i<n_righe; i++){
					elementi=new tipoelem*[n_colonne];
				}
				
			}
				for(i=0; i<n_righe; i++){          //se num righe e num colonne sono uguali passa subito a riscrivere la matrice
													//altrimenti prima ne modifica la dimensione
							for(j=0; j<n_colonne; j++){
								
								elementi[i][j]=m.elementi[i][j];
							}
				}			
		}
		return *this;
}


tipoelem matrice::leggiMatrice(int riga, int colonna){
	return elementi[riga][colonna];	
}


void matrice::scriviMatrice(int riga, int colonna, tipoelem elem){
	elementi[riga][colonna]=elem;
	
}

void matrice::stampa(){
	for(int i=0; i<n_righe; i++){
			
			for(int j=0; j<n_colonne; j++){
				
					std::cout<<elementi[i][j] <<" ";
			}
			std::cout<<endl;
	}
}

matrice matrice::trasposta(){
	matrice T(n_colonne,n_righe);
	
	for(int j=0; j<n_righe; j++){
		
				for(int i=0; i<n_colonne; i++){
		
								T.elementi[j][i]=elementi[i][j];
	         }	
		}
	return T;
			
}


matrice matrice::prodotto(matrice &m){
	if(n_colonne!=m.n_righe){
		cout<<"Prodotto non disponibile"<<endl;
	}else{
		matrice G(n_righe,m.n_colonne);
		for (int i=0;i<G.n_righe;i++) {
    		for (int j=0;j<G.n_colonne;j++) {
      				double k;
	  				int p=0;
      					for (int r=0;r<m.n_righe;r++) {
      							k=m.elementi[r][j];
      						    p=elementi[i][r]*k;
	  }
      G.scriviMatrice(i, j, p);
    }
  }
	
		return G;
	}
}

void matrice::prodottoScalare(double sc){
	for(int i=0; i<n_righe; i++){
		
			for(int j=0; j<n_colonne; j++){
				elementi[i][j]= sc*elementi[i][j];
			}
	}
}

void matrice::random(){
	for(int i=0; i<n_righe; i++){
		
			for(int j=0; j<n_colonne; j++){
				
				elementi[i][j]= rand() %100;
			}
	}
}


