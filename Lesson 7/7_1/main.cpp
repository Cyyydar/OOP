// Перегрузка оператора ++
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

    DinMas& operator++(){
        cout << "Operator increment (prefix)\n";
        if(Mas == nullptr)
            return *this;
        for(int i = 0; i < RazMas; i++) {
            ++Mas[i];
        }
        return *this;
    }

    const DinMas operator++(int x) {
        cout << "Operator incrementa (postfix)\n";
        if(Mas == nullptr)
            return *this;
        DinMas ob(*this);
        for(int i = 0; i < RazMas; i++) {
            ++Mas[i];
        }
        return ob;
    }
};

int main()
{
    DinMas Massiv1(4,4);
    cout << "\n Massive1: \n";
    Massiv1.Show();

    DinMas Massiv2(5,5);
    cout << "\n Massive2: \n";
    Massiv2.Show();

    cout<<"\n ++Massive1: \n";
    ++Massiv1;
    Massiv1.Show();

    cout<<"\n ++Massive2: \n";
    ++Massiv2;
    Massiv2.Show();

    cout<<"\n Massive2++: \n";
    Massiv2++;
    Massiv2.Show();
    return 0;
}


