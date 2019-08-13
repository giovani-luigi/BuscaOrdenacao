#include "ListItem.h"

using namespace std;

// construtor (cria o objeto e o inicializa)
ListItem::ListItem(TDado dado){
	this->dado = dado;
	this->prox = NULL;
}

ListItem::~ListItem(){
	prox = NULL;
}

// sobrescrita do operador de saída
ostream& operator<< (ostream& out, const ListItem& right){
	return out << right.dado;
}
