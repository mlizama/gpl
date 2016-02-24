
#include "symbol_table.h"
#include "error.h"
#include <vector>
#include <sstream>
#include <algorithm>

void Symbol_table::print(ostream &os)
{
	vector<string> names;
	//iterate through symbols and print them 
	for(unordered_map <string, Symbol*>::iterator iter = symbol_map.begin();iter != symbol_map.end();iter++)
	{	
		names.push_back(iter->second->s_id);
		//iter->second->print(os);
	}
	std::sort(names.begin(),names.end());
	for(int x = 0;x<(int)names.size();x++)
	{
		((symbol_map.find(names[x]))->second)->print(os);
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

