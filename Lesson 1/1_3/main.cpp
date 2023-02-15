#include <iostream>

using namespace std;


class A {
    public:
    A(){ // конструктор
        cout << "Constructor\n";
    }
    ~A(){ // деструктор
        cout << "Destructor\n";
    }
};


int main()
{
    A ob;

    return 0;
}
