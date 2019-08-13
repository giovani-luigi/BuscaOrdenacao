#include "ExtraTypes.h"
#include "ListItem.h"

#ifndef LIST_H
#define LIST_H

enum class ModoInsereLista{
	InsereNoInicio,
	InsereNoFim,
	Ordenado 
};

// Implementa��o de uma lista encadeada simples
class List{
	
	protected:
	
		ListItem *inicio;
		
	public:
		
		// construtor padr�o
		List();
		
		// destrutor
		~List();
				
		// adiciona um dado no fim da lista
		void insere(TDado valor, ModoInsereLista modo = ModoInsereLista::InsereNoFim);
		
		// remove TODOS itens que contem o valor indicado
		void remove(TDado valor);
		
		// remove todos os n�s da lista
		void limpa();
		
		// mostra todo o conte�do da lista na tela
		void mostra();
	
	private:
		
		// insere elemento na lista, respeitando a ordena��o
		void insereOrdenado(TDado valor);
		
		// insere elemento no in�cio da lista
		void insereNoInicio(TDado valor);
	
		// insere elemento no fim da lista
		void insereNoFim(TDado valor);
};

#endif
