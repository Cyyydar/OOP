#include <iostream>

using namespace std;

class A{

public:
    A(int x){}
};

class B : public A{

public:
    B(int y): A(y){}
};

int main()
{
//    B ob; - вызывет ошибку т.к. в конструктор необходимо передать значение
    B ob(1);

    return 0;
}
