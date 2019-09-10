#include "Sorter.h"

#ifndef SHELL_SORTER_H
#define SHELL_SORTER_H

class ShellSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		void ordenaDados(vector<TDado>& vetor);
};

#endif
