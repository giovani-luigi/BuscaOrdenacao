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
			// otimiza��o:
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
		// mostra na tela as estat�sticas referentes � �ltima opera��o de orderna��o
		void exibeEstatisticas();
		
		// m�todo padr�o que realiza a orderna��o
		void ordena(vector<TDado>& vetor);

		virtual const char* getNome();

};

#endif
