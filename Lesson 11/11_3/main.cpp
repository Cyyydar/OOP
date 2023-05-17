#include <iostream>

using namespace std;

double divide_float(float x, float y);

int main()
{
    float x, y;
    double z;
    cout << "Delimoe:";
    cin << x;
    cout << "Delitel:";
    cin << y;
    try{
        z = divide_float(x,y);
        cout << " " << x << " / " << y << " = " << z << endl;
    }
    catch(const char* exc){
        cerr << exc << endl;
    }
    cout << "Prodoljenie raboti main" << endl;
    return 0;
}

double divide_float(float x, float y){
    if(y == 0){
        throw "divide by zero";
    }
        return static_cast<double>(x)/y;
}
