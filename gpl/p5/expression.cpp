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
	//ignore o_type

}
Expression::Expression(Expression *left, Operator_type type, Expression *right)
{
	int_value = 0;//not used
	str_value = "";//not used
	dbl_value = 0.0;//not used
	leftxp = left;
	rightxp = right;
	m_kind = EXPRESSION;
	o_type = type;
	m_variable = NULL;
	//these operators only return an int
	if(o_type == LESS_THAN || o_type == LESS_THAN_EQUAL || o_type == GREATER_THAN || o_type == GREATER_THAN_EQUAL ||
	   o_type == AND || o_type == OR || o_type == EQUAL || o_type == NOT_EQUAL)
	{
		m_type = INT;
	}
	//if either left or right are strings then the expression evals to string covers arithmetic operators
	else if(left->get_type() == STRING || left->get_type() == STRING)
	{
		m_type = STRING;
	}
	//if either left or right are doubles then we know the result is double, strings take 
	else if(left->get_type() == DOUBLE || right->get_type() == DOUBLE)
	{
		m_type = DOUBLE;
	}
	//both left and right are int so result must be int
	else if(left->get_type() == INT || right->get_type() == INT)
	{
		m_type = INT;
	}

}
Expression::Expression(double d_value)
{
	int_value = 0;//default int if not int
	str_value = "";//default string if not string
	dbl_value = d_value;//set double value
	leftxp = NULL;
	rightxp = NULL;
	m_type = DOUBLE;//type is INT
	m_variable = NULL;
	m_kind = CONSTANT;
	//ignore o_type

}
Expression::Expression(string s_value)
{
	int_value = 0;//default int if not int
	str_value = s_value;//set string value
	dbl_value = 0.0;//default double if not double
	leftxp = NULL;
	rightxp = NULL;
	m_type = STRING;//type is INT
	m_variable = NULL;
	m_kind = CONSTANT;
	//ignore o_type

}

int Expression::eval_int()
{
	if(m_kind == CONSTANT && m_type == INT)
	{
		return int_value;
	}
	else
	{	
		return 0;
	}
	return 0;
}
double Expression::eval_double()
{
	if(m_kind == CONSTANT && m_type == DOUBLE)
	{
		return dbl_value;
	}
	else return 0;
}
string Expression::eval_string()
{
	if(m_kind == CONSTANT && m_type == STRING)
	{
		return str_value;
	}
	else return 0;
}
Gpl_type Expression::get_type()
{
	return m_type;
}
