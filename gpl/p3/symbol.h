#include "gpl_type.h"
#include <iostream>

using namespace std;

class Symbol
{

	public: string   s_name;
		Gpl_type g_type;
		int      i_value;
		double   d_value;
		string   s_value;

	Symbol(string name, Gpl_type type, int value);
	Symbol(string name, Gpl_type type, double value);
        Symbol(string name, Gpl_type type, string value);

	void print(ostream &os);

};
