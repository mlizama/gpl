#include "gpl_type.h"
#include <iostream>

using namespace std;
#ifndef SYMBOL_H
#define SYMBOL_H
class Symbol
{

	public: string   s_id;
		int	 s_size;
		Gpl_type s_type;
		void *   s_data;

	Symbol(string name, int value);
	Symbol(string name, double value);
        Symbol(string name, string value);
	Symbol(string name, Gpl_type type, int size);

	void print(ostream &os);

};

#endif
