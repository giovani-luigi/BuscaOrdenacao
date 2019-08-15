#include <iostream>
#include "List.h"

using namespace std;

// construtor padrão
List::List(){
	this->inicio = NULL;
}

void List::insereOrdenado(TDado valor){

	ListItem *novo = new ListItem(valor);
	
	if (!inicio){ // lista vazia
		inicio = novo;
		return;
	}
	
	// procura ponto de inserção
	ListItem *atual, *ant = NULL;
    for (atual=inicio; atual; ant=atual, atual=atual->prox)
        if (valor < atual->dado) break;

	// insere (caso inicio)
    if (atual == inicio) { 
        novo->prox = inicio;
        inicio = novo;
    } else {
	    // insere (caso ultimo)
	    ant->prox = novo;
	    // insere (caso meio)
	    if (atual) novo->prox = atual;
	}
}

void List::insereNoInicio(TDado valor){
	ListItem *novo = new ListItem(valor);
	novo->prox = inicio;
	inicio = novo;
}

void List::insereNoFim(TDado valor){

	ListItem *novo = new ListItem(valor);
	if (!inicio){ // lista vazia
		inicio = novo;
		return;
	}

	ListItem *p;
	for (p = inicio; p->prox; p=p->prox);
	p->prox = novo;
}

void List::insere(TDado valor, ModoInsereLista modo){
	switch(modo){
		case ModoInsereLista::InsereNoInicio:
			insereNoInicio(valor);
			break;
		case ModoInsereLista::InsereNoFim:
			insereNoFim(valor);
			break;
		case ModoInsereLista::Ordenado:
			insereOrdenado(valor);
			break;
	}	
}

void List::remove(TDado valor){
	
	ListItem *ant, *p;
	
	// se lista estiver vazia, nada pode ser removido
	if (!inicio) return;
	
	// posiciona o ponteiro no item para remoção
	for (ant=NULL, p=inicio; p; ant=p, p=p->prox)
        if (valor == p->dado) break;
    
    if (!p) return; // nao localizado
    
    //localizado no inicio
    if (p == inicio) { 
        inicio = inicio->prox;
        delete p;
        return;
    }    
    //encontrado na ultima posicao
	if (!p->prox) { 
        delete p;
        ant->prox = NULL;
        return;
    }
	// localizado no meio da lista:
	ant->prox = p->prox;
    delete p;
}

void List::limpa(){
	if (!inicio) return;
	
	ListItem *atual, *prox;
	
	atual = inicio;
	while (atual){
		prox = atual->prox;
		delete atual;
		atual = prox;
	}
	
	inicio = NULL;
}

void List::mostra(){
	ListItem* p;
	int64 i;
	for (p = inicio; p; p=p->prox, i++)
		cout << *p << endl;
}

// destrutor 
List::~List(){
	limpa();
}
