#include "Sorter.h"

void Sorter::ordenaDados(vector<TDado>& vetor){
	TDado* menor;
	int64 i, j;	

	for (i=0; i<vetor.size();i++){

		// mostra progresso da operação
		exibeProgresso(static_cast<float>(i)/vetor.size());
		
		menor = &vetor[i];
		for (j=i+1; j<vetor.size();j++){
			comparacoes++;
			if (vetor[j] < *menor)
				menor = &vetor[j];
		}
		if (menor != &vetor[i]){
			trocas++;
			swap(*menor, vetor[i]);
		}
	}
}

const char* Sorter::getNome(){ 
	return "Selection Sort";
}

void Sorter::ordena(vector<TDado>& vetor){
	
	zeraEstatisticas();
			
	clock_t startTime = clock();
	cout << "Ordenando com: " << this->getNome() << endl;
	
	ordenaDados(vetor);
	
	duracao = double(clock() - startTime) / CLOCKS_PER_SEC;
}

void Sorter::exibeEstatisticas(){
	cout << endl << "Tempo=" << duracao << " (segundos)"<< endl;
	cout << "Trocas=" << trocas << endl;
	cout << "Comparacoes=" << comparacoes << endl;
}
