#include <iostream>
#include "ExtraTypes.h"

#ifndef LIST_ITEM_H
#define LIST_ITEM_H

using namespace std;

// representa um n� de uma lista encadeada simples
class ListItem{
	
	public:
		
		// construtor (cria o objeto e o inicializa)
		ListItem(TDado dado);
	
		~ListItem();
	
		// ponteiro para o pr�ximo n�
		ListItem* prox;
	
		TDado dado;
		
		
};

// sobrescrita do operador de sa�da
ostream& operator<< (ostream& out, const ListItem& right);

#endif
