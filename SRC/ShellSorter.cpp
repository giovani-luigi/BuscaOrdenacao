#include "ShellSorter.h"
	
const char* ShellSorter::getNome(){ 
	return "Shell Sort";
}
	
void ShellSorter::ordenaDados(vector<TDado>& vetor){
		
	int64 i, j;
	TDado tmp;	
	
	// encontra o maior multiplo de 3 menor que o tamanho total do vetor.
	int64 distancia = 1;
	do {
		distancia = distancia * 3 + 1;
	} while (distancia < vetor.size());
	
	do{
		
		distancia /= 3;
		
		for (i=distancia; i<vetor.size(); i++){
			tmp = vetor[i];
			comparacoes++;
								
			for (j=i-distancia; j>=0 && tmp < vetor[j]; j=j-distancia){
				vetor[j+distancia] = vetor[j];
				comparacoes++;
				trocas++;
			}
			vetor[j+distancia] = tmp;
			trocas++;
		}		
		
	} while ( distancia > 1);

}
