#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

#include "ExtraTypes.h"

using namespace std;


// Classe base para objetos de ordenação de um vetor. 
// Novas classes de ordenação devem herdar esta classe (ver InsertionSorter por exemplo)
class Sorter{

	protected:
		
		// ***************************************************************************************
		// objetos membros da classe
		// ***************************************************************************************
		
		int64 trocas; 	 // toda vez que houver a troca de posição de um elemento, incrementar
		int64 comparacoes; // toda vez que houver comparação entre elementos, incrementar
		int64 progresso;
		int64 limiar;    // otimização para evitar atualização de tela muito frequente
		float duracao;

		// ***************************************************************************************
		// metodos
		// ***************************************************************************************
		
		// exibe o progresso na tela
		// - pct: o progress em porcentagem (0.0-1.0)
		inline void exibeProgresso(){
			// otimização:
			if ((progresso + limiar) < comparacoes){
				cout << "\rComparações: " << comparacoes;
				progresso = comparacoes;
			}
		}

		// reinicia os contadores
		inline void zeraEstatisticas(){
			trocas = comparacoes = duracao = progresso = 0;
		}		

		virtual void ordenaDados(vector<TDado>& vetor);

	public:		
		// mostra na tela as estatísticas referentes à última operação de ordernação
		void exibeEstatisticas();
		
		// método padrão que realiza a ordernação
		void ordena(vector<TDado>& vetor);

		virtual const char* getNome();
		
};

#endif
