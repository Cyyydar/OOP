// Наследование конструктора
#include <iostream>

using namespace std;

class A;
class B;

class A{
    int xa;
public:
    A(){cout << "Constructor classa A\n";}
    ~A(){cout << "Destructor classa A\n";}
    void setXa(int i) {xa = i;}
    int getXa(){return xa;}
};

class B : public A{
    int xb;
public:
    B(){cout << "Constructor classa B\n";}
    ~B(){cout << "Destructor classa B\n";}
    void setXb(int i) {xb = i;}
    int getXb(){return xb;}
};
int main()
{
    B ob;
    ob.setXb(1);
    cout << " ob.xb = " << ob.getXb() << endl;
    ob.setXa(2);
    cout << " ob.xa = " << ob.getXa() << endl;
    return 0;
}
