#ifndef SYMBOL_H
#define SYMBOL_H

#include "gpl_type.h"
#include "game_object.h"
#include <iostream>


using namespace std;

//class Game_object;
class Symbol
{

	public: 
		string   s_id;
		int	 s_size;
		Gpl_type s_type;
		void *   s_data;
		Gpl_type m_base;
		Game_object *game;

	Symbol(string name, int value);
	Symbol(string name, double value);
        Symbol(string name, string value);
	Symbol(string name, Gpl_type type, int size);
	Symbol(string name, Game_object *game_obj);

	Game_object * get_game_object_value();
	bool is_game_object();

	Gpl_type get_base_type();
	int get_int_value() const;
	double get_double_value() const;
	string get_string_value() const;
	Gpl_type get_type();
	int size(){return s_size;}

	int get_int_value(int index) const;
	double get_double_value(int index) const;
	string get_string_value(int index) const;

	void print(ostream &os);

};

#endif
