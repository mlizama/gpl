
#include "symbol_table.h"
#include "error.h"
#include <sstream>

void Symbol_table::print(ostream &os)
{
	//iterate through symbols and print them 
	for(unordered_map <string, Symbol*>::iterator iter = symbol_map.begin();iter != symbol_map.end();iter++)
	{
		iter->second->print(os);
	}
}
Symbol_table *Symbol_table::m_instance = NULL;

Symbol_table *Symbol_table::instance()
{
  if (m_instance == NULL)
    m_instance = new Symbol_table();
  return m_instance;
}
void Symbol_table::addSymbol(string key,Symbol *symbol)
{
	//check to see if the symbol is in the symbol table already
	if(symbol_map.find(key) == symbol_map.end())
	{
		symbol_map[key] = symbol;
	}
	else// if the symbol is in the symbol table already then throw error
	{
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, key);
	}
}
/*bool Symbol_table::exists(string key)
{
	if(symbol_map.find(key) != symbol_map.end()){return true;}
	else return false;
}*/

