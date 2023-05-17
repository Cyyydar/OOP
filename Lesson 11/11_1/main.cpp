#include <iostream>

using namespace std;

double divide_float(float, float);

int main()
{
    float x,y;
    double z;
    cout << "Delimoe: ";
    cin >> x;

    cout << "Delitel: ";
    cin >> y;

    z = divide_float(x,y);
    cout << " " << x << " / " << y << " = " << z << endl;
    return 0;
}

double divide_float(float x, float y){
    if(y == 0){
        throw "Oshibka. Delenie na NULL\n";
    }
    return static_cast<double>(x)/y;
}
