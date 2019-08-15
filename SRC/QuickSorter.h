#include "Sorter.h"

#ifndef QUICK_SORTER_H
#define QUICK_SORTER_H

class QuickSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
		
	private:
		
		int64 particiona(vector<TDado>& v, int64 ini, int64 fim);
		
		void quickSort(vector<TDado>& v, int64 ini, int64 fim);
};

#endif
