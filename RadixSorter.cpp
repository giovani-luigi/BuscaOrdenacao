#include "RadixSorter.h"

// ---------------------------------------------------------------------------------------------------
// Adaptação do algoritmo Radix Sort
// Fonte: https://www.geeksforgeeks.org/radix-sort/
// ---------------------------------------------------------------------------------------------------

// Função que retorna o valor máximo contido em um vetor
int getMax(vector<TDado> vetor) { 
    int max = vetor[0];
    for (int i = 1; i < vetor.size(); i++)
        if (vetor[i] > max) 
            max = vetor[i]; 
    return max;
} 

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(vector<TDado>& vetor, int exp) { 
	
	if (vetor.size() < 2) return;
	
	int *output = new int[vetor.size()]; // output    
		
    int i;
	int count[10] = {0}; // inicializa todos com Zero
  
    // Store count of occurrences in count[] 
    for (i = 0; i < vetor.size(); i++) 
        count[ (vetor[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Constrói a array de saída
    for (i = vetor.size() - 1; i >= 0; i--){ 
        output[count[ (vetor[i]/exp)%10 ] - 1] = vetor[i]; 
        count[ (vetor[i]/exp)%10 ]--; 
    } 
  
    // copia o resultado da array de saída output[]
    // para refletir a ordenação para o dígito especificado
    for (i = 0; i < vetor.size(); i++) 
        vetor[i] = output[i]; 
        
    delete[] output;
} 

// ---------------------------------------------------------------------------------------------------

// O algoritmo de ordenação radix sort foi originalmente usado para ordenar cartões perfurados.
// Um algoritmo computacional para o radix sort foi inventado em 1954 no MIT por Harold H. Seward.

const char* RadixSorter::getNome(){
	return "Radix Sorter";
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void RadixSorter::ordenaDados(vector<TDado>& vetor){
	
	// Find the maximum number to know number of digits 
    int max = getMax(vetor); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; max/exp > 0; exp *= 10) 
        countSort(vetor, exp);
	
}
