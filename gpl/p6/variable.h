#ifndef variable_h
#define variable_h

#include "symbol.h"
#include "gpl_type.h"
#include "animation_block.h"
#include "game_object.h"
#include <iostream>

class Expression;

class Variable
{
	private:
		Expression *exp;
		Variable *var;
		Symbol *sym;
		Gpl_type m_type;
		string m_id;
		Game_object *game;

	public:
		Variable(Symbol* symb);
		Variable(Symbol* symb, Expression *expp);
		Variable(string m_id1, Symbol* symb);
		Variable(string m_id1, Symbol* symb, Expression* expres);
		Gpl_type get_type();
		int get_int_value();
		double get_double_value();
		string get_string_value();
		Animation_block* get_animation_block();
};
#endif

