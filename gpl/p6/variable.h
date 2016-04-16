#ifndef variable_h
#define variable_h

#include "symbol.h"
#include "gpl_type.h"
#include <iostream>

class Expression;

class Variable
{
	private:
		Expression *exp;
		Variable *var;
		Symbol *sym;
		Gpl_type m_type;

	public:
		Variable(Symbol* symb);
		Variable(Symbol* symb, Expression *expp);
		Gpl_type get_type();
		int get_int_value();
		double get_double_value();
		string get_string_value();
};
#endif

