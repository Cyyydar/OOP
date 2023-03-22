//lvalue и rvalue ссылки
#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int &ra = a; //lvalue ссылка на а

//  int &rb = 10; //нельзя ссылаться на выражение ссылкой lvalue
//  int &rg = a - 4 //

    const int &re = 12;
    const int &rg = a - 4;

//  re = a + 10;
//  rg = 3;

    int&& rc = 100 + 200; // rvalue ссылка

    cout << "rc= " << rc << endl;
    rc++;
    cout << "rc= " << rc << endl;
    rc = 50;
    cout << "rc= " << rc << endl;
    return 0;
}
