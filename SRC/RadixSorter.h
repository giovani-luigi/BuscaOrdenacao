#include "Sorter.h"

#ifndef RADIX_SORTER_H
#define RADIX_SORTER_H

class RadixSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
};

#endif
