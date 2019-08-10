#include "Sorter.h"

class BubbleSorter : public Sorter{
	public:
		
		virtual const char* getNome();
		
		virtual void ordenaDados(vector<TDado>& vetor);
};
