#include <iostream>
#include "ExtraTypes.h"

#ifndef LIST_ITEM_H
#define LIST_ITEM_H

using namespace std;

// representa um nó de uma lista encadeada simples
class ListItem{
	
	public:
		
		// construtor (cria o objeto e o inicializa)
		ListItem(TDado dado);
	
		~ListItem();
	
		// ponteiro para o próximo nó
		ListItem* prox;
	
		TDado dado;
		
		
};

// sobrescrita do operador de saída
ostream& operator<< (ostream& out, const ListItem& right);

#endif
