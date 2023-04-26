#include "DinMas.h"

#include <iostream>

using namespace std;

void DinMas::Create (){
        if(Mas != nullptr) {
            cout << " Massiv uje zadan";
            for(int i = 0; i < RazMas; i++)
                cout << " " << Mas[i];
            cout << "\n Chtobi perezapisat vvedi - 1\n";
            cout << " Chtobi ne perezapisat vvedite - 0\n";
            int f;
            cin >> f;
            if(f == 0)
                return;
        }
        cout << "Vvedite razmer massiva (celoe chislo bolshe 0): ";
        cin >> RazMas;
        delete []Mas;
        Mas = new int[RazMas];
        cout << "Vvodite celie chisla: \n";
        for(int i = 0; i < RazMas; i++) {
            cout << " Mas [" << i << "] = ";
            cin >> Mas[i];
        }
        cout << " Vvod zavershon \n";
    }

void DinMas::Show() const{
    if(Mas == nullptr){
        cout << " Massiv ne bil zadan \n";
        return;
    }
    cout << " Vivod massiva: ";
    for(int i = 0; i < RazMas; i++) {
        cout << " " << Mas[i];
    }
    cout << "\n Adress nachala massiva: " << Mas << endl;
}
