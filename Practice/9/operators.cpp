#include "DinMas.h"

#include <iostream>

DinMas&DinMas::operator=(DinMas &&ob){
    if(this == &ob)
        return *this;
    delete[]Mas;
    Mas = nullptr;
    RazMas = 0;
    if((ob.Mas != nullptr) && (ob.RazMas != 0)) {
        Mas = ob.Mas;
        RazMas = ob.RazMas;
        ob.Mas = nullptr;
        ob.RazMas = 0;
    }
    std::cout << "\n Pereopredelennoe prisvoenie peremesheniem \n";
    return *this;
}

DinMas&DinMas::operator=(const DinMas &ob){
    if(this == &ob)
        return *this;
    delete[]Mas;
    Mas = nullptr;
    RazMas = 0;
    if((ob.Mas != nullptr) && (ob.RazMas != 0)) {
        Mas = new int[ob.RazMas];
        RazMas = ob.RazMas;
        for(int i = 0; i < ob.RazMas; i++){
            Mas[i] = ob.Mas[i];
        }
    }
    std::cout << "\n Pereopredelennoe prisvoenie \n";
    return *this;
}
