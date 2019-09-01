#include "QuickSorter.h"

int64 QuickSorter::particiona(vector<TDado>& v, int64 ini, int64 fim) {
	int64 pivo;

	pivo = ini;
	while (fim > ini) {
		
		for (; fim > pivo && v[fim] > v[pivo]; fim--, comparacoes++);

		if (fim > pivo) {
			swap(v[pivo], v[fim]);
			pivo = fim;
			trocas++;
		}
		
		for (ini++; ini < pivo && v[ini] < v[pivo]; ini++, comparacoes++);

		if (ini < pivo) {
			swap(v[pivo], v[ini]);
			pivo = ini;
			trocas++;
		}
		
	}
	return pivo;
}

void QuickSorter::quickSort(vector<TDado>& v, int64 ini, int64 fim){
	int64 pivo;
	pivo = particiona(v, ini, fim);
	if (ini < pivo - 1) quickSort(v, ini, pivo - 1);
	if (pivo + 1 < fim) quickSort(v, pivo + 1, fim);	
}

void QuickSorter::ordenaDados(vector<TDado>& vetor){
	quickSort(vetor, 0, vetor.size());	
}

	
const char* QuickSorter::getNome(){ 
	return "Quick Sort";
}
