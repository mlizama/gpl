#include "gpl_type.h"
#include <iostream>

using namespace std;

class Symbol
{

	public: string   s_id;
		Gpl_type s_type;
		void *   s_data;

	Symbol(string name, Gpl_type type, int value);
	Symbol(string name, Gpl_type type, double value);
        Symbol(string name, Gpl_type type, string value);

	void print(ostream &os);

};
