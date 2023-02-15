#include <iostream>

using namespace std;


// В классе все поля по умолчанию приватные
class A {
    int x;
    public:
    int y;
};


int main()
{
    A ob1, ob2; // Экземпляры (объекты) класса
    ob1.y = 3;
    ob2.y = 7;

    cout << "ob1.y = " << ob1.y << " ob2.y = " << ob2.y << endl;

//    Нельзя изменить приватные поля класса
//    ob1.x = 1;
//    ob2.x = 2;

    return 0;
}
