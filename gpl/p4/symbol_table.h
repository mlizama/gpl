
#include <iostream>
#include <unordered_map>
#include "symbol.h"
using namespace std;

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

// global_counter is used to demonstrate that all instances of class Foo
// are the same.  In other words, that class Foo is a singleton


// class Foo is a singleton
class Symbol_table
{
  public:

    static Symbol_table *instance();
    //void print() {cout << "Symbol_table(m_id = " << ")" << endl;}
    void print(ostream &os);
    void addSymbol(string key, Symbol *symbol);
    //bool exists(string key);
  private:

    unordered_map <string, Symbol*> symbol_map;
    static Symbol_table *m_instance;



    Symbol_table() {};

    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);

};


#endif





