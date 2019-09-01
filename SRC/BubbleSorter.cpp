#include "BubbleSorter.h"
	
const char* BubbleSorter::getNome(){ 
	return "Bubble Sort";
}
	
void BubbleSorter::ordenaDados(vector<TDado>& vetor){
	
	bool houveTroca;
	int64 i;

	do {
		houveTroca = false; //marca que nao houveTroca
	
		for (i = 0; i < vetor.size() - 1; i++) {			
			comparacoes++;
			if (vetor[i] > vetor[i + 1]) {
				swap(vetor[i], vetor[i+1]);
				trocas++;
				houveTroca = true;
			}
		}
		
	} while (houveTroca);
	
}
