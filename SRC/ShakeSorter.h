#include "Sorter.h"

#ifndef SHAKE_SORTER_H
#define SHAKE_SORTER_H

class ShakeSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
};

#endif
