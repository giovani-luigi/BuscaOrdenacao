#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

#include "Sorter.h"
#include "ExtraTypes.h"

#ifndef DATASET_H
#define DATASET_H

using namespace std;

class Dataset{
	private:
		
		// ***************************************************************************************
		// objetos membros da classe
		// ***************************************************************************************
		
		// armazena o conjunto de dados em RAM:
		// OBS: A classe 'vector' implementa um array para armazenamento dos dados, portanto
		//      o tempo de acesso � id�ntico ao de um array normal.
		vector<TDado> vetor;
		
	public:
		
		// ***************************************************************************************
		// objetos membros da classe
		// ***************************************************************************************
		
		// constante est�tica, com o nome de um arquivo utilizado por padr�o
		static const char* NOME_ARQUIVO_PADRAO;
		
		// ***************************************************************************************
		// constutores
		// ***************************************************************************************
		
		// construtor padr�o
		Dataset();
		
		// ***************************************************************************************
		// metodos
		// ***************************************************************************************
		
		// retorna um valor indicando se o arquivo existe em disco
		bool existeArquivo();
		
		// retorna um valor indicando se o conjunto de dados na mem�ria RAM est� ordenado
		bool estaOrdenado();
		
		// gera um conjunto de dados to tamanho especificado
		// - 	 quantia: a quantia de elementos a gerar
		// - valorMaximo: valor m�ximo a ser gerado
		void gera(int64 quantia, int valorMaximo);
		
		// mostra na tela o conjunto de dados
		// -  inicio: [opcional] o �ndice (come�ando em Zero) do primeiro valor a ser mostrado
		//			  Quando n�o especificado, inicia do Zero.
		// - quantia: [opcional] quantidade de elementos para mostrar, a partir do inicio. 
		// 			  Quando n�o especificado, retorna todos elementos at� o �ltimo.		
		void exibe(int64 inicio=0, int64 quantia=0);
		
		// apaga todo o conteudo da memoria RAM
		void limpa();
		
		// le um arquivo binario contendo os dados
		// - arquivo: [opcional] o caminho para o arquivo a ser aberto
		void abreArquivoBinario(const char* arquivo = NOME_ARQUIVO_PADRAO);
		
		// le um arquivo de texto contendo os valores em ASCII, separados por quebra de linha
		// - arquivo: [opcional] o caminho para o arquivo a ser lido
		void abreArquivoTexto(const char* arquivo = NOME_ARQUIVO_PADRAO);
		
		// grava o conjunto de dados, em um arquivo, em bin�rio, separados por quebra de linha
		// - arquivo: [opcional] o caminho para o arquivo a ser gravado
		void salvaArquivoBinario(const char* arquivo = NOME_ARQUIVO_PADRAO);
		
		// grava o conjunto de dados, em um arquivo, em ASCII, separados por quebra de linha
		// - arquivo: [opcional] o caminho para o arquivo a ser gravado
		void salvaArquivoTexto(const char* arquivo = NOME_ARQUIVO_PADRAO);
		
		// ordena o conjunto de dados em mem�ria, utilizando um classificador especificado
		// - classificador: um objeto capaz de ordenar objetos do tipo TDado
		void ordena(Sorter& classificador);
};

#endif

