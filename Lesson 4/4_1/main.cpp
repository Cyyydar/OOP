//Конструктор копирования и оператор присвоения
#include <iostream>

using namespace std;

class DinMassiv{
    double*Mas;
    int RazmerMas;
public:
    DinMassiv(int K, double x, double y);
    ~DinMassiv(){cout << "\n Destructor \n"; delete[]Mas;}
    DinMassiv(const DinMassiv &ob);
    DinMassiv& operator= (const DinMassiv &ob);

    void createMas();
    void showMas() const;
};

int main()
{
    DinMassiv ob1(6, 4.5, 7.3);
    ob1.showMas();
    ob1.createMas();
    ob1.showMas();
    DinMassiv ob2(0,0,0);
    ob2.showMas();
    ob2.createMas();
    ob2.showMas();
    DinMassiv ob3(ob1);
    ob3.showMas();
    DinMassiv ob4 = ob2;
    ob4.showMas();
    ob4 = ob3;
    ob4 = ob4;
    ob4.showMas();
    return 0;
}

DinMassiv::DinMassiv(int K, double x, double y){
    cout << "Costructor start working\n\n";
    if(K <= 0){
        cout << "Error: bad array size\n";
        Mas = nullptr;
        RazmerMas = 0;
        return;
    }
    RazmerMas = K;
    Mas = new double[RazmerMas];
    for(int i = 0; i < RazmerMas; i++)
        Mas[i] = (x-i)*(x+i)+y*y;
}
DinMassiv::DinMassiv(const DinMassiv &ob){
    cout << " Constructor of copy";
    if(this == &ob) {
        this->Mas = nullptr;
        this->RazmerMas = 0;
        return;
    }
    if(ob.Mas == nullptr){
        this->Mas = nullptr;
        this->RazmerMas = 0;
        return;
    }
    this->RazmerMas=ob.RazmerMas;
    this->Mas = new double[this->RazmerMas];
    for(int i = 0; i < this->RazmerMas; i++)
        this->Mas[i] = ob.Mas[i];
}

DinMassiv& DinMassiv::operator=(const DinMassiv &ob){
    cout << " Apropriation\n\n";
    if(this == &ob){
        cout << "Self copy error\n";
        return *this;
    }
    delete[]this->Mas;
    if(ob.Mas == nullptr){
        this->Mas = nullptr;
        this->RazmerMas = 0;
        return *this;
    }
    this->RazmerMas=ob.RazmerMas;
    this->Mas = new double[this->RazmerMas];
    for(int i = 0; i < this->RazmerMas; i++)
        this->Mas[i] = ob.Mas[i];
    return *this;
}

void DinMassiv::createMas(){
    if(Mas != nullptr) {
        cout << "Massiv already created\n";
        for(int i = 0; i < RazmerMas; i++)
            cout << " " << Mas[i];
        cout << "\nEnter 1 if need recreate array\n";
        cout << "Or 0\n";
        int f;
        cin >> f;
        if(f == 0)
            return;
    }
    cout << "Enter array size:\n";
    cout << "(positive integer number)";
    cin >> RazmerMas;
    delete[]Mas;
    Mas = new double[RazmerMas];
    cout << "Enter real numbers:\n";
    for(int i = 0; i < RazmerMas; i++){
        cout << " Mas [" << i << "] = ";
        cin >> Mas[i];
    }
    cout << "Entry complited\n";
}

void DinMassiv::showMas() const {
    if(Mas == nullptr){
        cout << " Array is not created\n\n";
        return;
    }
    cout << " Array:\n";
    for(int i = 0; i < RazmerMas; i++)
        cout << " " << Mas[i];
    cout << endl << endl;
}
