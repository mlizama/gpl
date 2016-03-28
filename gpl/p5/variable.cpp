#include "variable.h"
#include "expression.h"

Variable::Variable(Symbol* symb)
{
	//does not hold an expression ex: int y = (i + x)
	exp = NULL;
	sym = symb;
	m_type = sym->get_type();
	
}
Variable::Variable(Expression *expp)
{
	//does not hold a single var ex: int x = i;
	var = NULL;
	exp = expp;
	m_type = expp->get_type();

}
int Variable::get_int_value()
{
	if(var)
	{
		return sym->get_int_value();
		//return 0;
	}
	else//only called when this is an expression int x = a[5 + y]
	{
		//
		return 0;
	}
}
double Variable::get_double_value()
{
	if(var)
	{
		return sym->get_double_value();
	}
	else return 0.0;
}
string Variable::get_string_value()
{
	if(var)
	{
		return sym->get_string_value();
	}
	else return "";
}














