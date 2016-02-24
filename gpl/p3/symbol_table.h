/***
  Example of a singleton
***/

#include <iostream>
#include <map>
#include "symbol.h"
using namespace std;

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

// global_counter is used to demonstrate that all instances of class Foo
// are the same.  In other words, that class Foo is a singleton
//
//int global_counter = 42;

// class Foo is a singleton
class Symbol_table
{
  public:

    static Symbol_table *instance();
    //void print() {cout << "Symbol_table(m_id = " << ")" << endl;}
    void print(ostream &os);
    void addSymbol(string key, Symbol *symbol);
    bool exists(string key);
  private:
    //map <string, Symbol>::iterator iter;
    map <string, Symbol*> symbol_map;
    static Symbol_table *m_instance;


    // Note that the constructor is private
    Symbol_table() {};

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);

};


#endif





