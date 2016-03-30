#include "symbol.h"

Symbol::Symbol(string name, int value)
{
	int* tmp = new int;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = INT;
	s_id = name;
        m_base = INT;
}
Symbol::Symbol(string name, double value)
{
	double* tmp = new double;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = DOUBLE;
	s_id = name;
        m_base = DOUBLE;
}
Symbol::Symbol(string name, string value)
{
	
	s_data = (void*)new string(value);
	s_type = STRING;
	s_id = name;
        m_base = STRING;
}

Symbol::Symbol(string name, Gpl_type type, int size)
{
	s_type = type;
	s_id = name;
	s_size = size;

	if(type == INT_ARRAY)
	{
		m_base = INT;
		int *tmp = new int[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = 0;
		}
		s_data = (void*)tmp;
	}
	else if(type == DOUBLE_ARRAY)
	{
		m_base = DOUBLE;
		double *tmp = new double[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = 0.0;
		}
		s_data = (void*)tmp;
	}
	else
	{
		m_base = STRING;
		string *tmp = new string[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = "";
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
		os << "string " << s_id << " = \"" << *((string*)s_data) << "\""<< endl;
	}
	else if(s_type == INT_ARRAY)
	{
		for(int x = 0; x < s_size;x++)
		{
			os << "int " << s_id << "[" << x << "]" << " = "<< (((int*)s_data)[x]) << endl;
			
		}
	}
	else if(s_type == DOUBLE_ARRAY)
	{
		for(int x = 0; x < s_size;x++)
		{
			os << "double " << s_id << "[" << x << "]"  << " = "<< (((double*)s_data)[x]) << endl;
			
		}
	}
	else if(s_type == STRING_ARRAY)
	{
		for(int x = 0; x < s_size;x++)
		{
			os << "string " << s_id << "[" << x << "]"  << " = "<< "\""
			   << (((string*)s_data)[x]) << "\""<< endl;
			
		}
	}
}
int Symbol::get_int_value() const
{
	return *((int*)s_data);
}
double Symbol::get_double_value() const
{
	return *((double*)s_data);
}
string Symbol::get_string_value() const
{
	return *((string*)s_data);
}
int Symbol::get_int_value(int index) const
{

	return (((int*)s_data)[index]);//come back to this!!
}
double Symbol::get_double_value(int index) const
{
	return (((double*)s_data)[index]);//and this!!
}
string Symbol::get_string_value(int index) const
{	
	return (((string*)s_data)[index]);
}
Gpl_type Symbol::get_base_type()
{
	return m_base;
}
Gpl_type Symbol::get_type()
{
	return s_type;
}







