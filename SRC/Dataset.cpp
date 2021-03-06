#include "Dataset.h"
#include "Sorter.h"

const char* Dataset::NOME_ARQUIVO_PADRAO = "dados.bin";

// construtor padr�o
Dataset::Dataset(){
}

// **********************************************************************************
// METODOS P�BLICOS
// **********************************************************************************

// gera um conjunto de dados to tamanho especificado
// - 	 quantia: a quantia de elementos a gerar
// - valorMaximo: valor m�ximo a ser gerado
void Dataset::gera(int64 quantia, TDado valorMaximo){
	srand(clock());
	for (int64 i=0; i<quantia; i++)
		vetor.push_back(rand() % (valorMaximo+1));
}

// apaga todo o conteudo da memoria RAM
void Dataset::limpa(){

	// --------------------------------------------------------
	// destroys data container and de-allocate it:
	// --------------------------------------------------------
	vetor.clear(); // destroy all objects but underlying array 
	// remains allocated (sizeof(T)*vector.size()  bytes at least)

	// shrink_to_fit() is not guaranteed to free memory, instead we use the swap() trick:
	vector<int>().swap(vetor); // swap the vector with an empty vector.
	// This will de-allocate the memory taken by the vector (guaranteed)
	// --------------------------------------------------------
}

// mostra na tela o conjunto de dados
// -  inicio: [opcional] o �ndice (come�ando em Zero) do primeiro valor a ser mostrado
//			  Quando n�o especificado, inicia do Zero.
// - quantia: [opcional] quantidade de elementos para mostrar, a partir do inicio. 
// 			  Quando n�o especificado, retorna todos elementos at� o �ltimo.		
void Dataset::exibe(int64 inicio, int64 quantia){

	// se quantia n�o for especificada, utiliza todos elementos
	if (quantia == 0) quantia = (vetor.size() - inicio);
	
	for (int64 i=inicio; i<(inicio+quantia); i++)
		cout << "Item[" << i << "]=" << vetor[i] << "\t\t";
}

// retorna um valor indicando se o conjunto de dados na mem�ria RAM est� ordenado
bool Dataset::estaOrdenado(){

	// sempre que tiver menos de 2 elementos, est� ordenado
	if (vetor.size() < 2) return true;
	
	for (int i = 0; i< vetor.size()-1;i++)
		if (vetor[i+1] < vetor[i]) 
			return false;
	return true;
}

void Dataset::abreArquivoBinario(const char* arquivo){

	// antes de abrir, vamos limpar o vetor
	limpa();
	
	// abre arquivo para leitura, no modo bin�rio
	ifstream ifs(arquivo, ios::binary);
	
	TDado valor;
	while (ifs.read((char*)&valor, sizeof(TDado)))
		vetor.push_back(valor);
	ifs.close();
	
	cout << "Arquivo aberto. Valores lidos=" << vetor.size() << endl;
}

void Dataset::salvaArquivoBinario(const char* arquivo){
	
	// abre arquivo para escrita, no modo bin�rio
	ofstream fs(arquivo, ios::binary);
	
	fs.write((char*)(vetor.data()), vetor.size() * sizeof(TDado) );
	fs.close();
}

void Dataset::ordena(Sorter& classificador){
	classificador.ordena(vetor);
}

int Dataset::busca(int valor){
	for (int i=0; i < vetor.size(); i++)
		if (valor==vetor[i]) 
			return i;
	return -1;
}

int Dataset::buscaBinaria(int valor){

	int64 ini;
	int64 meio;
	int64 fim = vetor.size()-1;
	
	while (ini <= fim){
		meio = (fim+ini)/2;
		if (vetor[meio] == valor)
			return meio;
		if ( valor < vetor[meio])
			fim = meio-1;
		else
			ini = meio+1;
	}
	return -1;
}

void Dataset::abreArquivoTexto(const char* arquivo){
}

void Dataset::salvaArquivoTexto(const char* arquivo){	
}
