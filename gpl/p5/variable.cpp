#include "variable.h"
#include "expression.h"
#include <assert.h>     /* assert */


Variable::Variable(Symbol* symb)
{
	//does not hold an expression ex: int y = (i + x)
	exp = NULL;

	sym = symb;
	m_type = sym->get_type();
	assert(symb != NULL);
}
Variable::Variable(Expression *expp)
{

	//does not hold a single var ex: int x = i;
	var = NULL;
	exp = expp;
	m_type = expp->get_type();
	assert(exp != NULL);
}
int Variable::get_int_value()
{//stuck here
	//assert((exp != NULL && sym != NULL));
	if(sym)
	{
		return sym->get_int_value();
		//return 0;
	}
	else if (exp)//only called when this is an expression int x = a[5 + y]
	{
		//
		return 9;
	}
	return 0;
}
double Variable::get_double_value()
{
	if(sym)
	{
		return sym->get_double_value();
	}
	else return 0.0;
}
string Variable::get_string_value()
{
	if(sym)
	{
	
		return sym->get_string_value();

	}
	else return "";
}
Gpl_type Variable::get_type()
{
	return m_type;
}













