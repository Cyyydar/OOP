#include <iostream>

using namespace std;

class A{

public:
    A(int x){}
};

class B : public A{

public:
    B(int x, int y): A(x){} // x для A, у для В
};

int main()
{
//    B ob; - вызывет ошибку т.к. в конструктор необходимо передать значение
    B ob(1,2);

    return 0;
}
