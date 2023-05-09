#include "DinMas.h"

#include <iostream>

void DinMas::Create (){
        if(Mas != nullptr) {
            std::cout << " Massiv uje zadan";
            for(int i = 0; i < RazMas; i++)
                std::cout << " " << Mas[i];
            std::cout << "\n Chtobi perezapisat vvedi - 1\n";
            std::cout << " Chtobi ne perezapisat vvedite - 0\n";
            int f;
            std::cin >> f;
            if(f == 0)
                return;
        }
        std::cout << "Vvedite razmer massiva (celoe chislo bolshe 0): ";
        std::cin >> RazMas;
        delete []Mas;
        Mas = new int[RazMas];
        std::cout << "Vvodite celie chisla: \n";
        for(int i = 0; i < RazMas; i++) {
            std::cout << " Mas [" << i << "] = ";
            std::cin >> Mas[i];
        }
        std::cout << " Vvod zavershon \n";
    }
