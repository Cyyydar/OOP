// Перегрузка оператора сложения
#include <iostream>

using namespace std;

class DinMas{

    int RazMas = 0;
    int *Mas = nullptr;

public:
    DinMas(const DinMas &ob): Mas{nullptr}, RazMas{0} {
        if((ob.Mas != nullptr) && (ob.RazMas != 0)){
            Mas = new int [ob.RazMas];
            RazMas = ob.RazMas;
            for(int i = 0; i < ob.RazMas; i++)
                Mas[i] = ob.Mas[i];
        }
        cout << "\n Constructor kopirovaniya \n";
    }

    DinMas& operator=(const DinMas &ob){
        if(this == &ob)
            return *this;
        delete[]Mas;
        Mas = nullptr;
        RazMas = 0;
        if((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = new int[ob.RazMas];
            RazMas = ob.RazMas;
            for(int i = 0; i < ob.RazMas; i++){
                Mas[i] = ob.Mas[i];
            }
        }
        cout << "\n Pereopredelennoe prisvoenie \n";
        return *this;
    }

    DinMas(DinMas&&ob): Mas{nullptr}, RazMas{0} {
        if((ob.Mas != nullptr) && (ob.RazMas != 0)){
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr;
            ob.RazMas = 0;
        }
        cout << "\n Kopirovanie peremesheniem \n";
    }

    DinMas&operator=(DinMas &&ob){
        if(this == &ob)
            return *this;
        delete[]Mas;
        Mas = nullptr;
        RazMas = 0;
        if((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr;
            ob.RazMas = 0;
        }
        cout << "\n Pereopredelennoe prisvoenie peremesheniem \n";
        return *this;
    }

    DinMas(int k, int m): Mas{nullptr}, RazMas{0} {
        cout << "\n Konstructor s parametrami \n";
        if(k < 1)
            return;
        RazMas = k;
        Mas = new int[RazMas];
        for(int i = 0; i < RazMas; i++)
            Mas[i] = m;
    }

    DinMas(): Mas{nullptr}, RazMas{0} {
        cout << "\n Konstructor bez parametrov \n";
    }

    ~DinMas(){
        delete[]Mas;
        cout << "\n Destructor porabotal";
    }

    void Create (){
        if(Mas != nullptr) {
            cout << " Massiv uje zadan";
            for(int i = 0; i < RazMas; i++)
                cout << " " << Mas[i];
            cout << "\n Chtobi perezapisat vvedi - 1\n";
            cout << " Chtobi ne perezapisat vvedite - 0\n";
            int f;
            cin >> f;
            if(f == 0)
                return;
        }
        cout << "Vvedite razmer massiva (celoe chislo bolshe 0): ";
        cin >> RazMas;
        delete []Mas;
        Mas = new int[RazMas];
        cout << "Vvodite celie chisla: \n";
        for(int i = 0; i < RazMas; i++) {
            cout << " Mas [" << i << "] = ";
            cin >> Mas[i];
        }
        cout << " Vvod zavershon \n";
    }

    void Show() const{
        if(Mas == nullptr){
            cout << " Massiv ne bil zadan \n";
            return;
        }
        cout << " Vivod massiva: ";
        for(int i = 0; i < RazMas; i++) {
            cout << " " << Mas[i];
        }
        cout << "\n Adress nachala massiva: " << Mas << endl;
    }

    friend DinMas operator+(const DinMas &ob1, const DinMas &ob2);
};

int main()
{
    DinMas ob1{4, 4};
    DinMas ob2{10, 10};
    DinMas ob3;
    ob3 = ob1 + ob2;
    ob3.Show();

    return 0;
}

DinMas operator+(const DinMas &ob1, const DinMas &ob2){
    cout << "Operator + nachal rabotu\n";
    DinMas ob3;
    if((ob1.RazMas != 0) || (ob2.RazMas != 0)){
        if(ob1.RazMas > ob2.RazMas){
            ob3.RazMas = ob1.RazMas;
            ob3.Mas = new int[ob3.RazMas];
            for(int i=0; i < ob1.RazMas; i++){
                ob3.Mas[i] = ob1.Mas[i];
            }
            for(int i=0; i = ob2.RazMas; i++){
                ob3.Mas[i] += ob2.Mas[i];
            }
        } else {
            ob3.RazMas = ob2.RazMas;
            ob3.Mas = new int[ob3.RazMas];
            for(int i=0; i < ob3.RazMas; i++){
                ob3.Mas[i] = ob2.Mas[i];
            }
            for(int i=0; i < ob1.RazMas; i++){
                ob3.Mas[i] += ob1.Mas[i];
            }
        }
    }
    cout << "Operator+ zakonchil rabotu";
    return ob3;
}
