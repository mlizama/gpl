#include<iostream>
#include"symbol.h"

using namespace std;

int main()
{

Symbol *test =  new Symbol("test",10);
Symbol *test1 =  new Symbol("test1","test");
Symbol *test2 =  new Symbol("test2",1.1);

cout << test->s_id<< endl;
cout << test->s_type<< endl;
cout << *((int*)(test->s_data))<< endl;
cout << endl;
cout << test1->s_id<< endl;
cout << test1->s_type<< endl;
cout << *((string*)(test1->s_data))<< endl;
cout << endl;
cout << test2->s_id<< endl;
cout << test2->s_type<< endl;
cout << *((double*)(test2->s_data))<< endl;


return 0;
}
