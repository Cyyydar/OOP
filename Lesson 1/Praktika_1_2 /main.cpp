#include <iostream>

using namespace std;


class A {
    int x;
    public:
    void set_x(int i){x = i;} // сеттер - устанавливает значение
    int get_x(){return x;} // геттер - возвращает значение
};


int main()
{
    A ob;

    ob.set_x(5);
    cout << " ob.x = " << ob.get_x() << endl;

    return 0;
}
