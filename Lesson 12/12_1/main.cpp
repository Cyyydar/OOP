#include <iostream>

int main()
{
    try{
        throw 5;
    }
    catch(double x){
        std::cout << "poimano iskluchenie tipa double:" << x << '\n';
    }
    catch(...){
        std::cout << "poimano iskluchenie neopredelennogo tipa";
    }
    return 0;
}
