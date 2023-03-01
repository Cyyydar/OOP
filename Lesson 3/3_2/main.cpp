#include <iostream>

using namespace std;
// Класс, реализующий динамический массив

// методы должны вызываться в любом порядке и не приводить к неопределенному результату
class DM {
    int *Mas;
    int K;
    public:
    DM(): /*Инизиализация*/ Mas{nullptr}, K{0} {cout << "constructor \n";}
    DM(const DM &ob): Mas{nullptr}, K{0}{
        if(this == &ob){ // проверка на самокопирование
            return;
        }
        if(ob.Mas == nullptr){ // проверка на нулевой массив
            return; // если он нулевого размера, то мы ничего не меняем
        }
        this->K = ob.K; //this - указатель на самого себя
        this->Mas = new int[K];
        for(int i = 0; i < K; i++){
            this->Mas[i] = ob.Mas[i];
        }
        cout << "\n Copy constructor \n";
    }
    ~DM(){
        delete[]Mas;
        cout << "destructor \n";
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
        cout << "\n Adress of start array: " << Mas << endl;
    }
};


int main()
{
//    DM massiv1;
//    massiv1.create();
//    cout << "\n\n massiv1: \n\n";
//    massiv1.print();
//
//    DM massiv2 = massiv1;
//    cout << "\n\n massiv2: \n\n";
//    massiv2.print();
    DM ob1;
    ob1.print();
    DM ob2{ob1};
    ob2.print();
    ob1.create();
    ob1.print();
    DM ob3{ob1};
    ob3.print();
    DM ob4{ob4};
    ob4.print();
    return 0;
}
