#include "InsertionSorter.h"

const char* InsertionSorter::getNome(){
	return "Insertion Sorter";
}

void InsertionSorter::ordenaDados(vector<TDado>& vetor){
	
	TDado aux;
	int64 i, j;
	
	for ( i=1; i<vetor.size();i++){
		aux = vetor[i];
		comparacoes++;

		for( j = i-1; j>=0 && vetor[j]>aux ; j--){
			// desloca toda a coleção para a direita
			vetor[j+1] = vetor[j];
			comparacoes++;
			trocas++;
		}
		vetor[j+1]=aux;
		trocas++;
	}
	
}
