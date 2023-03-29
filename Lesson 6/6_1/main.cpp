// дружественная функция
#include <iostream>

using namespace std;

class A{
    int b;
  public:
    friend void show_b(const A&);
};

int main()
{
    A ob1;
    show_b(ob1);
    return 0;
}

void show_b(const A&ob){
    cout << " b=" << ob.b << endl;
}
