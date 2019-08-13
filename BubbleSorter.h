#include "Sorter.h"

#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

class BubbleSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
};

#endif
