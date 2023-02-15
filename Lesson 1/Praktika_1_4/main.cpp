#include <iostream>

using namespace std;
// Простейший конструктор и деструктор для класса, реализующего динамический массив

class DM {
    int *Mas;
    int K;
    public:
    DM(): /*Инизиализация*/ Mas{nullptr}, K{0} {/* Тело */}
    ~DM(){
        delete[]Mas;
    }
};


int main()
{

    return 0;
}
