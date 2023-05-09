#include "DinMas.h"

#include <iostream>

void DinMas::Show() const{
    if(Mas == nullptr){
        std::cout << " Massiv ne bil zadan \n";
        return;
    }
    std::cout << " Vivod massiva: ";
    for(int i = 0; i < RazMas; i++) {
        std::cout << " " << Mas[i];
    }
    std::cout << "\n Adress nachala massiva: " << Mas << std::endl;
}
