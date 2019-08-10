#include <iostream>

#include "Dataset.h"
#include "Sorter.h"
#include "BubbleSorter.h"

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
	int64 count = (int64)pedeNumero("Digite a quantidade de valores a gerar: ");
	
	Dataset dados;
	dados.gera(count, VALOR_MAXIMO);
	dados.salvaArquivoBinario();
}

// gera arquivo se n�o existir
void carregaDados(){
	
	cout << "Carregando dados..." << endl;

	// quando n�o existe, cria arquivo
	ifstream ifs(Dataset::NOME_ARQUIVO_PADRAO);
	if (!ifs.good()) 
		criaNovoArquivo();
}

// realiza a ordena��o dos dados
void ordenaDados(){
	
	// coloca todos os dados do arquivo na RAM	
	Dataset dados;	
	dados.abreArquivoBinario();
	
	
	// cria um objeto capaz de ordenar os dados
	Sorter sorter; // instancia no stack um objeto do tipo Sorter (� a clase base, que implementa um Selection sort)
	// - outros metodos de ordena��o dever�o herdar da classe base Sorter. (ver BubbleSorter por exemplo)
	
	// substitua o objeto acima pela linah abaixo, para usar BubbleSort ao inves de SelectionSort
	// BubbleSorter sorter;

	dados.ordena(sorter);

	sorter.exibeEstatisticas();
	
	// verifica se ficou ordenado:
	cout << "Esta ordenado= " << dados.estaOrdenado()<< endl << endl;
	
	cout << "Pressione ENTER para mostrar o resultado. CTRL+C para sair." << endl;
	cin.ignore();
	cin.get();
	
	// mostra todos os dados	
	dados.exibe();
	
}

int main(int argc, char** argv) {
	
	carregaDados();
	
	ordenaDados();
	
	return 0;
}
