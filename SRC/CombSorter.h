#include "Sorter.h"

#ifndef COMB_SORTER_H
#define COMB_SORTER_H

class CombSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
};

#endif
