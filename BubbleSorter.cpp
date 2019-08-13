#include "BubbleSorter.h"
	
const char* BubbleSorter::getNome(){ 
	return "Bubble Sort";
}
	
void BubbleSorter::ordenaDados(vector<TDado>& vetor){
	TDado* menor;
	int64 i, j;

	for (i=0; i<vetor.size();i++){

		// mostra progresso da operação
		exibeProgresso(static_cast<float>(i)/vetor.size());
		
		menor = &vetor[i];
		for (j=i+1; j<vetor.size();j++){
			comparacoes++;
			if (vetor[j] > *menor)
				menor = &vetor[j];
		}
		if (menor != &vetor[i]){
			trocas++;
			swap(*menor, vetor[i]);
		}
	}
}
