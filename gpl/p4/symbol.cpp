#include "symbol.h"

Symbol::Symbol(string name, int value)
{
	int* tmp = new int;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = INT;
	s_id = name;

}
Symbol::Symbol(string name, double value)
{
	double* tmp = new double;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = DOUBLE;
	s_id = name;
}
Symbol::Symbol(string name, string value)
{
	s_data = (void*)new string(value);
	//s_data = (void*)tmp;
	s_type = STRING;
	s_id = name;
}

void Symbol::print(ostream &os)
{
	/*if(g_type == INT)
	{
		os << "int " << s_name << " " << i_value << endl;
	}
	else if(g_type == DOUBLE)
	{
		os << "double " << s_name << " " << d_value << endl;
	}
	else if(g_type == STRING)
	{
		os << "string " << s_name << " \"" << s_value <<"\"" << endl;
	}*/
}


