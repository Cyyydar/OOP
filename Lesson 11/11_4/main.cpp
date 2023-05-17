#include <iostream>

using namespace std;

void f4(){
    cout << "f4 nachal raboty\n";
    cout << "f4 vibrosila iskluchenie int\n";
    throw -1;
    cout << "f4 zavershil raboty\n";
}

void f3(){
    cout << "f3 nachal raboty\n";
    f4();
    cout << "f3 zavershil raboty\n";
}

void f2(){
    cout << "f2 nachal raboty\n";
    try{
        f3();
    }
    catch (double){
        cerr << " f2 poimala iskluchenie double\n";
    }
    cout << "f2 zavershil raboty\n";
}

void f1(){
    cout << "f1 nachal raboty\n";
    try {
    f2();
    }
    catch(int){
        cerr << "f1 poimala isklucheine int\n";
    }
    catch(double){
        cerr << "f1 poimala isklucheine double\n";
    }
    cout << "f1 zavershil raboty\n";
}

int main()
{
    cout << "main nachal raboty\n";
    try{
        f1();
    }
    catch (int){
        cerr << " main poimala ickluchenie int\n";
    }
    return 0;
}
