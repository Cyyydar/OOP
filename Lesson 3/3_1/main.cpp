// конструктор копирования
#include <iostream>

using namespace std;

const int K{10};

class DinMas;
void f1(DinMas ob);
void f2(DinMas &ob);

class DinMas{
    int*Mas;
    int RazMas;
public:
    DinMas(const DinMas &ob) {
        RazMas = K;
        Mas = new int[RazMas];
        for(int i = 0; i < RazMas; i++){
            Mas[i] = ob.Mas[i];
        }
        cout << "\n Copy constructor";
    }

    DinMas(){
        RazMas = K;
        Mas = new int [RazMas];
        for(int i = 0; i < RazMas; i++){
            Mas[i] = 1;
        }
        cout << "\n Constructor is finished\n";
    }
    ~DinMas(){
        delete[]Mas;
        cout << "\n Destructor is finished\n";
    }
    void print() {
        for(int i = 0; i < K; i++){
            cout << " " << Mas[i];
        }
        cout << "\n Adress of start array: " << Mas << endl;
    }
};

int main()
{
    DinMas Massiv1;
    cout << "\n Massiv1: \n";
    Massiv1.print();
    DinMas Massiv2 = Massiv1;
    cout << "\n Massiv2: \n";
    DinMas Massiv3(Massiv1);
    cout << "\n Massiv3: \n";
    Massiv3.print();

    return 0;
}

void f1(DinMas ob){
    cout << "f1:\n";
    ob.print();
}

void f2(DinMas &ob){
    cout << "f2:\n";
    ob.print();
}
