#include "expression.h"

Expression::Expression(int i_value)
{
	int_value = i_value;//set int value
	str_value = "";//default string if not string
	dbl_value = 0.0;//default double if not double
	leftxp = NULL;
	rightxp = NULL;
	m_type = INT;//type is INT
	m_variable = NULL;
	m_kind = CONSTANT;
	//ignore m_oper

}
int Expression::eval_int()
{
	if(m_kind == CONSTANT && m_type == INT)
	{
		return int_value;
	}
	else return 0;
}
Gpl_type Expression::get_type()
{
	return m_type;
}
