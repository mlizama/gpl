
#include <iostream>
#include <unordered_map>
#include "symbol.h"

using namespace std;

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

class Symbol_table
{
  public:

    static Symbol_table *instance();
    void print(ostream &os);
    void addSymbol(string key, Symbol *symbol);

  private:

    unordered_map <string, Symbol*> symbol_map;
    static Symbol_table *m_instance;

    Symbol_table() {};

    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);

};


#endif





