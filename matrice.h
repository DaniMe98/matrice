#ifndef MATRICE_H
#define MATRICE_H

typedef double tipoelem;


class matrice{
	public:
		matrice(int x,int y);
		~matrice();  //distruttore
		matrice(const matrice &); //costruttore di copia
		matrice & operator=(const matrice &);   //operatore di assegnamento (crea un altra matrice ma con lo stesso spazio di memoria,senza occuparne altra se la prima non serve)		
		tipoelem leggiMatrice(int riga,int colonna);
		void scriviMatrice(int riga,int colonna,tipoelem elem);
		void prodottoScalare(double scalare);
		matrice trasposta();
		matrice prodotto(matrice &);
		void stampa();
		void random();
		
	
	private:
		int n_righe;
		int n_colonne;
		tipoelem **elementi;	
};




#endif
