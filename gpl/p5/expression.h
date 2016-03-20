#ifndef expression_h
#define expression_h

#include "expression.h"
#include "gpl_type.h"

class Expression
{
	private:

	public:
	Expression(Expression *left,Gpl_type type, Expression *right);
};
#endif
