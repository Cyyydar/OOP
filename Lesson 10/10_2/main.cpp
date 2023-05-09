#include <iostream>

long long fib(int n);

int main(){

    int a ;
    std::cout << "Enter integer number:\n";
    std::cin >> a;

    if(fib(a) < 0){
        std::cerr << " Error\n";
        return 0;
    }

    std::cout << "Result fib(" << a << "): ";
    std::cout << fib(a) << std::endl;

    return 0;

}

long long fib(int n) {
    if( n < 1) {
        return -1;
    }

    if (n == 1) {
        return 0;
    }

    if (n == 2) {
        return 1;
    }

    return fib(n-2) + fib(n-1);
}

