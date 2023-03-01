#include <iostream>

using namespace std;
// Класс, реализующий динамический массив

// методы должны вызываться в любом порядке и не приводить к неопределенному результату
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
    void print() const { //константный метод не дает ничего менять
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
    void setElem(int i, int elem) {
        if(Mas == nullptr){
            cout << "Array is not created\n";
            return;
        }
        if(i >= K){
            cout << "Exit outside of array\n";
            return;
        }

        Mas[i] = elem;

    }
    int getElem(int i) const {
        if(Mas == nullptr){
            cout << "Array is not created (0 returned)\n";
            return 0;
        }
        if(i >= K){
            cout << "Exit outside of array (0 returned)\n";
            return 0;
        }

        return Mas[i];
    }
};


int main()
{
    DM massiv_1;
    massiv_1.create();
    cout << massiv_1.getElem(100) << endl;
    cout << massiv_1.getElem(2) << endl;
    massiv_1.setElem(2,99);
    cout << massiv_1.getElem(2) << endl;

    return 0;
}
