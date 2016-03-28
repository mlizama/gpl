#ifndef expression_h
#define expression_h

#include "expression.h"
#include "gpl_type.h"
#include <iostream>

using namespace std;

class Variable;

class Expression
{
	private:
	enum Tree_kinds {EXPRESSION, CONSTANT, VARIABLE};
	Tree_kinds m_kind;
	Expression *leftxp;
	Expression *rightxp;
	Variable *m_variable;
	Gpl_type m_type;
	Operator_type o_type;
	int int_value;
	string str_value;
	double dbl_value;
	

	public:
	Expression(Expression *left, Operator_type type, Expression *right);
	Expression(Expression *exp, Operator_type type);
        Expression(int i_value);
	Expression(double d_value);
        Expression(string s_value);
	Expression(Variable *variable);
	int eval_int();
	double eval_double();
	string eval_string();
	Gpl_type get_type();

};
#endif
