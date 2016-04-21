#include "symbol.h"
#include "triangle.h"
#include "circle.h"
#include "rectangle.h"
#include "pixmap.h"
#include "textbox.h"


Game_object* Symbol::get_game_object_value_at_index(int index) 
{
  return ((Game_object**)s_data)[index];
}
Animation_block* Symbol::get_animation_block_value()
{
	return block;
}
bool Symbol::is_game_object()
{
	if(s_type == GAME_OBJECT)
	{
		return true;	
	}
	else
	{
		return false;
	}
}
Symbol::Symbol(string name, Animation_block *a_block)
{
	s_type = ANIMATION_BLOCK;
	s_id = name;
	block = a_block;
	s_data = NULL;
}
void Symbol::set(int x)
{
	int* tmp = new int;
	*tmp = x;
	s_data = (void*)tmp;
}
Game_object* Symbol::get_game_object_value()
{
	return game;	
}
Symbol::Symbol(string name, Game_object *game_obj)
{
	s_type = GAME_OBJECT;
	s_id = name;
	game = game_obj;
	s_data = NULL;
}
Symbol::Symbol(string name, int value)
{
	int* tmp = new int;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = INT;
	s_id = name;
        m_base = INT;
}
Symbol::Symbol(string name, double value)
{
	double* tmp = new double;
	*tmp = value;
	s_data = (void*)tmp;
	s_type = DOUBLE;
	s_id = name;
        m_base = DOUBLE;
}
Symbol::Symbol(string name, string value)
{
	
	s_data = (void*)new string(value);
	s_type = STRING;
	s_id = name;
        m_base = STRING;
}

Symbol::Symbol(string name, Gpl_type type, int size)
{
	s_type = type;
	s_id = name;
	s_size = size;

	if(type == INT_ARRAY)
	{
		m_base = INT;
		int *tmp = new int[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = 0;
		}
		s_data = (void*)tmp;
	}
	else if(type == DOUBLE_ARRAY)
	{
		m_base = DOUBLE;
		double *tmp = new double[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = 0.0;
		}
		s_data = (void*)tmp;
	}
	else if (type == STRING_ARRAY)
	{
		m_base = STRING;
		string *tmp = new string[size];
		for(int x = 0; x<size; x++)
		{
			tmp[x] = "";
		}
		s_data = (void*)tmp;
	}
	else //(type == GAME_OBJECT)
	{				
		s_type = GAME_OBJECT_ARRAY;
		Game_object** tmp = new Game_object*[size];
		for(int x = 0;x < size; x++)
		{
			if(type == CIRCLE)
			{

				m_base = CIRCLE;
				tmp[x] = new Circle();
			}
			else if(type == RECTANGLE)
			{
				m_base = RECTANGLE;
				tmp[x] = new Rectangle();
			}
			else if(type == TRIANGLE)
			{
				m_base = TRIANGLE;
				tmp[x] = new Triangle();
			}
			else if(type == PIXMAP)
			{
				m_base = PIXMAP;
				tmp[x] = new Pixmap();
			}
			else if(type == TEXTBOX)
			{
				m_base = TEXTBOX;
				tmp[x] = new Textbox();
			}
	
		}
		s_data = tmp;
	}
	

}

void Symbol::print(ostream &os)
{

	if(s_type == INT)
	{
		os << "int " << s_id << " = " << *((int*)s_data) << endl;
	}
	else if(s_type == DOUBLE)
	{
		os << "double " << s_id << " = " << *((double*)s_data) << endl;
	}
	else if(s_type == STRING)
	{
		os << "string " << s_id << " = \"" << *((string*)s_data) << "\""<< endl;
	}
	else if(s_type == INT_ARRAY)
	{
		for(int x = 0; x < s_size;x++)
		{
			os << "int " << s_id << "[" << x << "]" << " = "<< (((int*)s_data)[x]) << endl;
			
		}
	}
	else if(s_type == DOUBLE_ARRAY)
	{
		for(int x = 0; x < s_size;x++)
		{
			os << "double " << s_id << "[" << x << "]"  << " = "<< (((double*)s_data)[x]) << endl;
			
		}
	}
	else if(s_type == STRING_ARRAY)
	{
		for(int x = 0; x < s_size;x++)
		{
			os << "string " << s_id << "[" << x << "]"  << " = "<< "\""
			   << (((string*)s_data)[x]) << "\""<< endl;
			
		}
	}

	else if(s_type == GAME_OBJECT)
	{
		game->print(s_id,os);
	}
	else if(s_type == ANIMATION_BLOCK)
	{
		os << "animation_block " << s_id << endl;
	}
	else if(s_type == GAME_OBJECT_ARRAY)
	{
		//cout << s_size;
		for(int x = 0; x < s_size; x++)
		{
			string name = s_id + "[" + to_string(x) + "]";
      			((Game_object**)s_data)[x]->print(name, os);
		}

	}
}
int Symbol::get_int_value() const
{
	return *((int*)s_data);
}
double Symbol::get_double_value() const
{
	return *((double*)s_data);
}
string Symbol::get_string_value() const
{
	return *((string*)s_data);
}
int Symbol::get_int_value(int index) const
{

	return *((int*)s_data + index);//come back to this!!
}
double Symbol::get_double_value(int index) const
{
	return *((double*)s_data + index);//and this!!
}
string Symbol::get_string_value(int index) const
{	
	return *((string*)s_data + index);
}
Gpl_type Symbol::get_base_type()
{
	return m_base;
}
Gpl_type Symbol::get_type()
{
	return s_type;
}







