#include "Sorter.h"

#ifndef INSERTION_SORTER_H
#define INSERTION_SORTER_H

class InsertionSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
};

#endif
