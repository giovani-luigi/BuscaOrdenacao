#include <iostream>

#include "List.h"

#include "Dataset.h"
#include "Sorter.h"
#include "BubbleSorter.h"
#include "CombSorter.h"
#include "ShakeSorter.h"
#include "ShellSorter.h"
#include "InsertionSorter.h"
#include "RadixSorter.h"
#include "QuickSorter.h"

const int VALOR_MAXIMO = 999;	

// Pede ao usu�rio para entrar com um n�mero
int64 pedeNumero(const char* message){
	int64 result = 0;
	cout << message; 
	cin >> result;
	return result;
}

void criaNovoArquivo(){
	
	// pede quantidade de valores a gerar
	int64 count = (int64)pedeNumero("Digite a quantidade de valores a gerar: (Sugest�o: 25K) ");
	
	Dataset dados;
	dados.gera(count, VALOR_MAXIMO);
	dados.salvaArquivoBinario();
}

// gera arquivo se n�o existir
void carregaDados(){
	
	cout << "Validando arquivo de dados..." << endl;

	// quando n�o existe, cria arquivo
	ifstream ifs(Dataset::NOME_ARQUIVO_PADRAO);
	if (!ifs.good()) 
		criaNovoArquivo();
}

void testaOrdenacaoBuscaBinaria(){
	
	Dataset dados;
	
	clock_t inicio = clock();
	
	RadixSorter sorter;
	dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
	cout << "Esta ordenado (antes)= " << dados.estaOrdenado() << endl;
	dados.ordena(sorter);
	sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
	// verifica se ordena��o ocorreu corretamente
	cout << "Esta ordenado (depois)= " << dados.estaOrdenado() << endl;
	int64 pos = dados.buscaBinaria( 9999999 );
	float segundos = (float)(clock() - inicio) / CLOCKS_PER_SEC;
	cout << "Duracao Total binaria=" << segundos << endl << endl;
}

void testaOrdenacaoBuscaSequencial(){
	
	Dataset dados;
	
	clock_t inicio = clock();
	
	RadixSorter sorter;
	dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
	cout << "Esta ordenado (antes)= " << dados.estaOrdenado() << endl;
	int64 pos = dados.busca(999999);
	float segundos = (float)(clock() - inicio) / CLOCKS_PER_SEC;
	cout << "Duracao Total sequencial=" << segundos << endl << endl;
}

// realiza a ordena��o dos dados
void testaOrdenacao(){
	
	Dataset dados;	
	
	// SELECTION SORT
	{
		Sorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// BUBBLE SORT
	{
		BubbleSorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// SHAKE SORT
	{
		ShakeSorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// INSERTION SORT
	{
		InsertionSorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// SHELL SORT
	{
		ShellSorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// COMB SORT
	{
		CombSorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;	
	}	
	
	// RADIX SORT
	{
		RadixSorter sorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(sorter);
		sorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}	
	
	cout << "Pressione ENTER para mostrar o resultado da �ltima ordena��o. CTRL+C para sair." << endl;
	cin.ignore();
	cin.get();
	
	// mostra todos os dados	
	dados.exibe();
	
}

void testaLista(){
	
	List* l = new List();
	
	srand(clock());
	
	for (int i=1; i<=500;i++)
		l->insere(static_cast<int64>( rand() % 100 ), ModoInsereLista::Ordenado);
	
	l->mostra();
	
	delete l;
	
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "portuguese");
	
//	testaLista();
	
	carregaDados();
	
	cout << "Dados v�lidos. Pronto para iniciar." << endl;
	system("pause");
	cout << endl << endl;
		
	//testaOrdenacao();
	
	testaOrdenacaoBuscaBinaria();
	testaOrdenacaoBuscaSequencial();
	
	return 0;
}
