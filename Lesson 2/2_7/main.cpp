#include <iostream>

using namespace std;

class A{

public:
    A(int x){}
};

class B : public A{

public:
    B(int y, int x) : A(x){}
};

class C : public B{

public:
    C(int z, int x, int y) : B(y,x) {}
    /*
        z -> C
        x -> B -> A
        y -> B -> B
    */
};

int main()
{
//    B ob; - вызывет ошибку т.к. в конструктор необходимо передать значение
    C ob(1,2,3);

    return 0;
}
