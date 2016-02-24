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
	s_type = STRING;
	s_id = name;
}

Symbol::Symbol(string name, Gpl_type type, int size)
{
	s_type = type;
	s_id = name;
	
	if(type == INT_ARRAY)
	{
		int *tmp = new int[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = 42;
		}
		s_data = (void*)tmp;
	}
	else if(type == DOUBLE_ARRAY)
	{
		double *tmp = new double[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = 3.145;
		}
		s_data = (void*)tmp;
	}
	else
	{
		string *tmp = new string[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = "Hello world";
		}
		s_data = (void*)tmp;
	}
	

}

void Symbol::print(ostream &os)
{
	if(s_type == INT)
	{
		os << "int " << s_id << " = " << *((int*)s_data) << endl;
	}
	else if(s_type == DOUBLE)
	{
		os << "double " << s_id << " = " << *((double*)s_data) << endl;
	}
	else if(s_type == STRING)
	{
		os << "string " << s_id << " = \"" << *((string*)s_data) <<"\"" << endl;
	}
}


