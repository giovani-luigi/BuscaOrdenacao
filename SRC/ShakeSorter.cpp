#include "ShakeSorter.h"

const char* ShakeSorter::getNome(){ 
	return "Shake Sort";
}
	
void ShakeSorter::ordenaDados(vector<TDado>& vetor){

	bool houveTroca;
	int64 ini=0;
	int64 fim=vetor.size()-1;

	do {
	
		houveTroca=false;
		for (int64 i=ini; i<fim ;i++){
			comparacoes++;
			if (vetor[i] > vetor[i+1]){
				swap(vetor[i], vetor[i+1]);
				trocas++;
				houveTroca=true;
			}
		}
		fim--;

		if (!houveTroca) return;

		houveTroca=false;
		for (int64 i=fim; i>ini ;i--){
			comparacoes++;
			if (vetor[i-1] > vetor[i]){
				swap(vetor[i-1], vetor[i]);
				trocas++;
				houveTroca=true;
			}
		}
		ini++;
		
	} while (houveTroca && ini<fim);
	
}
