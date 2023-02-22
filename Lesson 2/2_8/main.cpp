#include <iostream>

using namespace std;

class A{
protected: // К полям со спецификатором protected можно обращаться из классов наследников, но не из вне
    static const int N{5}; // static выдеяет память под переменную
    int Mas[N] = {12,0,-4,5,-7};
public:
    void showMas() const{
        cout << " Massiv:\n";
        for(int i = 0; i < N; i++) {
            cout << " " << Mas[i];
        }
        cout << endl << endl;
    }
};

class B : public A {
public:
    void showMax() const{
        int d = Mas[0];
        for(int i = 1; i < N; i++){
            if(d < Mas[i]){
                d = Mas[i];
            }
        }
        cout << "Max = " << d << endl << endl;
    }
};

int main()
{
    B ob;
    ob.showMax();
    return 0;
}
