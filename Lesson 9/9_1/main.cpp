#include <iostream>

#include "A.h"
#include "B.h"
#include "D.h"
#include "show.h"

int main()
{
    D ob3;
    ob3.setN(3);
    std::cout << ob3.getN() << std::endl;
    A ob1;
    ob1.set_x(2.5);
    std::cout << ob1.get_x() << std::endl;
    B ob2;
    ob2.set_y(-9.1);
    std::cout << ob2.get_y() << std::endl;

    show(ob1, ob2);
    return 0;
}
