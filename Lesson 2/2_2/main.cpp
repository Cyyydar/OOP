#include <iostream>

using namespace std;
class A;
class B;
class C;
class D;
class E;

class A{

};
class B : public A{ // B наследует от А

};
class C : public B{ // C наследует от В

};
class D{

};
class E : public A, public D { // E - наследует от A и D

};

int main()
{
    return 0;
}
