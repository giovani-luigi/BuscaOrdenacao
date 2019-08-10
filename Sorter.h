#include <iostream>
#include <vector>
#include <ctime>

#include "ExtraTypes.h"

#ifndef SORTER_H
#define SORTER_H

using namespace std;

class Sorter{

	protected:
		
		// ***************************************************************************************
		// objetos membros da classe
		// ***************************************************************************************
		
		int trocas, comparacoes, progresso;
		float duracao;

		// ***************************************************************************************
		// metodos
		// ***************************************************************************************
		
		// exibe o progresso na tela
		// - pct: o progress em porcentagem (0.0-1.0)
		inline void exibeProgresso(float pct){
			int integral = static_cast<int>(pct*100);
			// otimização:
			if (progresso != integral){
				cout << "\rProgresso: " << integral << "%";
				progresso = integral;
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
