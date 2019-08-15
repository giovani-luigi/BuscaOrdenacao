#include <iostream>

#include "List.h"

#include "Dataset.h"
#include "Sorter.h"
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

// realiza a ordena��o dos dados
void ordenaDados(){
	
	Dataset dados;	
	
	// SELECTION SORT
	{
		Sorter selectionSorter; // sorter padr�o (classe base), implementa um Selection Sort
		dados.abreArquivoBinario(); // obtem conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(selectionSorter);
		selectionSorter.exibeEstatisticas(); // obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// INSERTION SORT
	{
		InsertionSorter insertionSorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(insertionSorter);
		insertionSorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;
	}
	
	// QUICK SORT
	{
		QuickSorter quickSorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(quickSorter);
		quickSorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
		// verifica se ordena��o ocorreu corretamente
		cout << "Esta ordenado (depois)= " << dados.estaOrdenado()<< endl << endl;	
	}	
	
	// RADIX SORT
	{
		RadixSorter radixSorter;
		dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
		cout << "Esta ordenado (antes)= " << dados.estaOrdenado()<< endl;
		dados.ordena(radixSorter);
		radixSorter.exibeEstatisticas();	// obtem estat�sticas referentes ao objeto sorter
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
		
	ordenaDados();
	
	return 0;
}
