//Перегрузка оператора присвоения
#include <iostream>

using namespace std;

const int K = 10;

class DinMas {
    int *Mas;
    int RazMas;
public:
    //DinMas& operator = (const DinMas &ob);
    DinMas(int x);
    ~DinMas();
    void show();
};

int main()
{
    DinMas Massiv1(1), Massiv2(2), Massiv3(3);
    cout << "\n Massiv1:\n";
    Massiv1.show();
    cout << "\n Massiv2:\n";
    Massiv2.show();
    cout << "\n Massiv3:\n";
    Massiv3.show();

    cout << "\n Massiv2 = Massiv1 = Massiv3: \n";
    Massiv2 = Massiv1 = Massiv3;

    cout << "\n Massiv1:\n";
    Massiv1.show();
    cout << "\n Massiv2:\n";
    Massiv2.show();
    cout << "\n Massiv3:\n";
    Massiv3.show();

    cout << "\n Massiv3 = Massiv3: \n";
    Massiv3 = Massiv3;

    cout << "\n Massiv3:\n";
    Massiv3.show();
    return 0;
}

DinMas& DinMas::operator=(const DinMas &ob){
    if(this == &ob){
        cout << "\n Self copy error\n";
        return *this;
    }
    for(int i = 0; i < this -> RazMas; i++)
        this->Mas[i] = ob.Mas[i];
    cout << "\n Appropriation \n";
    return *this;
}

DinMas::DinMas(int x = 0){
    RazMas = K;
    Mas = new int[RazMas];
    for(int i = 0; i < RazMas; i++) Mas[i] = x;
    cout << "\n Constructor has finished \n";
}

DinMas::~DinMas(){
    delete[]Mas;
    Mas = nullptr;
    cout << "\n Destructor has finished \n";
}

void DinMas::show(){
    for(int i = 0; i < RazMas; i++)
        cout << " " << Mas[i];
}


