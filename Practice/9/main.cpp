// конструктор перемещения и оператор перемещения присвоением
#include <iostream>

#include "DinMas.h"

using namespace std;

void obmen_kopirovaniem(DinMas &a, DinMas &b){
    DinMas c{a};
    a = b;
    b = c;
}

void obmen_peremesheniem(DinMas &a, DinMas&b){
    DinMas c = static_cast<DinMas&&>(a); //move(a);
    a = static_cast<DinMas&&>(b); //move(b);
    b = static_cast<DinMas&&>(c); //move(c);
}

int main()
{
    const int KOL = 10;
    DinMas Massiv[KOL];

    for(int i = 0; i < KOL; i++)
        Massiv[i] = DinMas(i+1,i+1);

    cout << "\n Vivod massivov: \n\n";

    for(int i = 0; i < KOL; i++){
        Massiv[i].Show();
        cout << endl;
    }

    obmen_kopirovaniem(Massiv[0],Massiv[9]);

    for(int i = 0; i < KOL; i++){
        Massiv[i].Show();
        cout << endl;
    }

    obmen_peremesheniem(Massiv[1], Massiv[8]);

    for(int i = 0; i < KOL; i++){
        Massiv[i].Show();
        cout << endl;
    }

    return 0;
}
