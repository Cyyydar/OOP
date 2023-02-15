#include <iostream>

using namespace std;
// Класс, реализующий динамический массив

class DM {
    int *Mas;
    int K;
    public:
    DM(): /*Инизиализация*/ Mas{nullptr}, K{0} {/* Тело */}
    ~DM(){
        delete[]Mas;
    }
    void create(){
        if(Mas!=nullptr){
            delete[]Mas;
        }
        int a;
        cout << "Enter array size ";
        cout << "(int > 0):\n";
        cin >> a;
        if(a < 1) {
            cout << "incorrect array size\n";
            return;
        }

        K = a;
        Mas = new int[K];
        cout << "Enter " << K << " integer numbers:\n";
        for(int i = 0; i < K; i++){
            cin >> Mas[i];
        }
    }
    void print(){
        if(Mas == nullptr || K == 0){
            cout << "Array is not created\n";
            return;
        }
        cout << "Array:\n";
        for(int i = 0; i < K; i++){
            cout << " " << Mas[i];
        }
        cout << endl;
    }
};


int main()
{
    DM massiv_1;
    massiv_1.print();
    massiv_1.create();
    massiv_1.print();
    massiv_1.create();
    massiv_1.print();

    return 0;
}
