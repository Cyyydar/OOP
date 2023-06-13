#include <iostream>

using namespace std;

//статические переменные существуют вне объекта и все время работы программы
//связывают все объекты класса единой областью в памяти
class A{
    int x;
    static int y; //Статический член
    static const int N{10};
    int arr[N]; // массив должен иметь размер
public:
    int get_x() {return x;}
    static int get_y() {return y;}
    void set_x(int a) {x = a;}
    static void set_y(int a) {y = a;}
};

int A::y = 0; //Выделение памяти

int main()
{
    cout << "A::y = " << A::get_y() << endl; // статические функции можно вызывать от имени класса
    //cout << "A::x = " << A::get_x() << endl; // Ошибка
    A::set_x(999);
    A ob1, ob2, ob3;
    ob1.set_x(1);
    ob2.set_x(2);
    ob3.set_x(3);

    ob1.set_y(11);
    ob2.set_y(22);
    ob3.set_y(33);

    cout << "ob1.x = " << ob1.get_x() << " ob1.y = " << ob1.get_y() << endl;
    cout << "ob2.x = " << ob2.get_x() << " ob2.y = " << ob2.get_y() << endl;
    cout << "ob3.x = " << ob3.get_x() << " ob3.y = " << ob3.get_y() << endl;
    return 0;
}
