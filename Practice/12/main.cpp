#include <iostream>
#include <math.h>
double divide_float(float, float);
double sqroot(float);

int main()
{
    float x, y;
    std::cout << "Enter first float number:\n";
    std::cin >> x;
    std::cout << "Enter second float number:\n";
    std::cin >> y;

    try{
        std::cout << x << " / " << y << " = " << divide_float(x,y) << '\n';
        std::cout << "square root by " << x << " = " << sqroot(x) << '\n';
        std::cout << "square root by " << y << " = " << sqroot(y) << '\n';
    }
    catch(...){
        std::cout << "poimano iskluchenie neopredelennogo tipa";
    }
    return 0;
}

double divide_float(float x, float y){
    if(y == 0){
        throw "Exception: divide by zero\n";
    }
    return static_cast<double>(x)/y;
}


double sqroot(float n){
    if (n < 0){
        throw "Exception: parameter is unavalible";
    }
    return static_cast<double>(sqrt(n));
}
