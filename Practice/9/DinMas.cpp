#include "DinMas.h"

#include <iostream>

using namespace std;

DinMas::DinMas(const DinMas &ob): Mas{nullptr}, RazMas{0} {
    if((ob.Mas != nullptr) && (ob.RazMas != 0)){
        Mas = new int [ob.RazMas];
        RazMas = ob.RazMas;
        for(int i = 0; i < ob.RazMas; i++)
            Mas[i] = ob.Mas[i];
    }
    cout << "\n Constructor kopirovaniya \n";
}

DinMas::DinMas(DinMas&&ob): Mas{nullptr}, RazMas{0} {
    if((ob.Mas != nullptr) && (ob.RazMas != 0)){
        Mas = ob.Mas;
        RazMas = ob.RazMas;
        ob.Mas = nullptr;
        ob.RazMas = 0;
    }
    cout << "\n Kopirovanie peremesheniem \n";
}

DinMas::DinMas(int k, int m): Mas{nullptr}, RazMas{0} {
    cout << "\n Konstructor s parametrami \n";
    if(k < 1)
        return;
    RazMas = k;
    Mas = new int[RazMas];
    for(int i = 0; i < RazMas; i++)
        Mas[i] = m;
}

DinMas::DinMas(): Mas{nullptr}, RazMas{0} {
    cout << "\n Konstructor bez parametrov \n";
}

DinMas::~DinMas(){
    delete[]Mas;
    cout << "\n Destructor porabotal";
}

