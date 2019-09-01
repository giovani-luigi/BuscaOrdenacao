#include "CombSorter.h"
	
const char* CombSorter::getNome(){ 
	return "Comb Sort";
}
	
void CombSorter::ordenaDados(vector<TDado>& vetor){
	
	int64 distancia = vetor.size();
	bool houveTroca;
	
	do{
		
		houveTroca = false;
		
		distancia /= 1.3;
		
		if (distancia<1) distancia = 1;
		
		for(int i=0; i + distancia < vetor.size(); i++){
			if ( vetor[i] > vetor[i+distancia] ){
				swap(vetor[i], vetor[i+distancia]);
				houveTroca = true;
			}
				
		}
		
	} while ( houveTroca || distancia > 1);

}
