#ifndef expression_h
#define expression_h

#include "expression.h"
#include "gpl_type.h"
#include <iostream>
#include "variable.h"
using namespace std;

class Expression
{
	private:
	enum Tree_kinds {EXPRESSION, CONSTANT, VARIABLE};
	Tree_kinds m_kind;
	Expression *leftxp;
	Expression *rightxp;

	public:
	Expression(Expression *left, Operator_type type, Expression *right);
	Expression(Expression *exp, Operator_type type);
        Expression(int i_value ,Gpl_type type);
	Expression(double d_value, Gpl_type type);
        Expression(string value, Gpl_type type);
	Expression(Variable *variable);

};
#endif
