#include "symbol.h"

Symbol::Symbol(string name, Gpl_type type, int value)
{
	int* tmp = new int;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = type;
	s_id = name;

}
Symbol::Symbol(string name, Gpl_type type, double value)
{
	/*d_value = value;
	g_type = type;
	s_name = name;*/
}
Symbol::Symbol(string name, Gpl_type type, string value)
{
	/*s_value = value;
	g_type  = type;
	s_name = name;*/
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


