#include <iostream>

#include "List.h"

#include "Dataset.h"
#include "Sorter.h"
#include "InsertionSorter.h"

const int VALOR_MAXIMO = 999;	

// Pede ao usuário para entrar com um número
int64 pedeNumero(const char* message){
	int64 result = 0;
	cout << message; 
	cin >> result;
	return result;
}

void criaNovoArquivo(){
	
	// pede quantidade de valores a gerar
	int64 count = (int64)pedeNumero("Digite a quantidade de valores a gerar: ");
	
	Dataset dados;
	dados.gera(count, VALOR_MAXIMO);
	dados.salvaArquivoBinario();
}

// gera arquivo se não existir
void carregaDados(){
	
	cout << "Validando arquivo de dados..." << endl;

	// quando não existe, cria arquivo
	ifstream ifs(Dataset::NOME_ARQUIVO_PADRAO);
	if (!ifs.good()) 
		criaNovoArquivo();
}

// realiza a ordenação dos dados
void ordenaDados(){
	
	Dataset dados;	
	
	// cria objetos de ordenação para testar
	Sorter selectionSorter; // sorter padrão (classe base), implementa um Selection Sort
	InsertionSorter insertionSorter;

	// metodo 1
	dados.abreArquivoBinario(); // obtem conjunto de dados do arquivo
	dados.ordena(selectionSorter);
	selectionSorter.exibeEstatisticas(); // obtem estatísticas referentes ao objeto sorter
	// verifica se ordenação ocorreu corretamente
	cout << "Esta ordenado= " << dados.estaOrdenado()<< endl << endl;
	
	// metodo 2
	dados.abreArquivoBinario(); // recarrega conjunto de dados do arquivo
	dados.ordena(insertionSorter);
	insertionSorter.exibeEstatisticas();	// obtem estatísticas referentes ao objeto sorter
	// verifica se ordenação ocorreu corretamente
	cout << "Esta ordenado= " << dados.estaOrdenado()<< endl << endl;
	
	cout << "Pressione ENTER para mostrar o resultado da última ordenação. CTRL+C para sair." << endl;
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
	
	cout << "Dados válidos. Pronto para iniciar." << endl;
	system("pause");
	cout << endl << endl;
		
	ordenaDados();
	
	return 0;
}
