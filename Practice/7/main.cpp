#include <iostream>

using namespace std;

class DinMas{

    int RazMas = 0;
    int *Mas = nullptr;

    int sum() const{
        int temp = 0;
        for(int i = 0; i < RazMas; i++){
            temp += Mas[i];
        }
        return temp;
    }

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
        if(k < 1)
            return;
        RazMas = k;
        Mas = new int[RazMas];
        for(int i = 0; i < RazMas; i++)
            Mas[i] = m;
    }

    DinMas(): Mas{nullptr}, RazMas{0} {

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
        cout << endl;
    }

    friend bool operator==(const DinMas&ob1, const DinMas&ob2);
    friend bool operator!=(const DinMas&ob1, const DinMas&ob2);
    friend bool operator>(const DinMas&ob1, const DinMas&ob2);
    friend bool operator>=(const DinMas&ob1, const DinMas&ob2);
    friend bool operator<(const DinMas&ob1, const DinMas&ob2);
    friend bool operator<=(const DinMas&ob1, const DinMas&ob2);
};

int main()
{
    DinMas Massiv1(6, 6);
    cout << "\n Massive1: \n";
    Massiv1.Show();

    DinMas Massiv2(5,10);
    cout << "\n Massive2: \n";
    Massiv2.Show();

    DinMas Massiv3(12,3);
    cout << "\n Massive3: \n";
    Massiv3.Show();

    cout << "Massiv1 == Massiv2 " << (Massiv1 == Massiv2) << endl;
    cout << "Massiv1 == Massiv3 " << (Massiv1 == Massiv3) << endl << endl;


    cout << "Massiv1 > Massiv2 " << (Massiv1 > Massiv2) << endl;
    cout << "Massiv1 >= Massiv2 " << (Massiv1 >= Massiv2) << endl;
    cout << "Massiv1 < Massiv2 " << (Massiv1 < Massiv2) << endl;
    cout << "Massiv1 <= Massiv2 " << (Massiv1 <= Massiv2) << endl << endl;

    cout << "Massiv1 < Massiv3 " << (Massiv1 < Massiv3) << endl;
    cout << "Massiv1 <= Massiv3 " << (Massiv1 <= Massiv3) << endl;

    return 0;
}


bool operator==(const DinMas&ob1, const DinMas&ob2){
    if(ob1.sum() == ob2.sum())
        return true;
}

bool operator!=(const DinMas&ob1, const DinMas&ob2){
    return !(ob1 == ob2);
}

bool operator>(const DinMas&ob1, const DinMas&ob2){
    if(ob1.sum() > ob2.sum())
        return true;
    return false;
}

bool operator>=(const DinMas&ob1, const DinMas&ob2){
    if(ob1.sum() >= ob2.sum())
        return true;
    return false;
}

bool operator<(const DinMas&ob1, const DinMas&ob2){
    if(ob1.sum() < ob2.sum())
        return true;
    return false;
}

bool operator<=(const DinMas&ob1, const DinMas&ob2){
    if(ob1.sum() <= ob2.sum())
        return true;
    return false;
}



