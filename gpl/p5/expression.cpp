#include "expression.h"

Expression::Expression(int i_value)
{
	int_value = i_value;
	leftxp = NULL;
	rightxp = NULL;
	m_type = INT;
	m_variable = NULL;
	//ignore m_oper

}
