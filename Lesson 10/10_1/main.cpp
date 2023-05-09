#include <iostream>

using namespace std;

float f1(float x);

int main()
{
    float x = 0;
    cout << "Enter float number:\n";
    cin >> x;

    cout << "Result f1(" << x << "): " << f1(x);

    return 0;
}

float f1(float x) {
    if(x != 0)
        return 1/x;
    std::cerr << "Invalid parameter\n";
    return -1;
}
