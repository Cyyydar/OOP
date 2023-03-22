// конструктор перемещения и оператор перемещения присвоением
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

    DinMas&operator=(const DinMas &ob){
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
};

void obmen_kopirovaniem(DinMas &a, DinMas &b){
    DinMas c{a};
    a = b;
    b = c;
}

void obmen_peremesheniem(DinMas &a, DinMas&b){
    DinMas c = static_cast<DinMas&&>(a); //move(a);
    a = static_cast<DinMas&&>(b); //move(b);
    b = static_cast<DinMas&&>(c); //move(c);
}

int main()
{
    const int KOL = 10;
    DinMas Massiv[KOL];

    for(int i = 0; i < KOL; i++)
        Massiv[i] = DinMas(i+1,i+1);

    cout << "\n Vivod massivov: \n\n";

    for(int i = 0; i < KOL; i++){
        Massiv[i].Show();
        cout << endl;
    }

    obmen_kopirovaniem(Massiv[0],Massiv[9]);

    for(int i = 0; i < KOL; i++){
        Massiv[i].Show();
        cout << endl;
    }

    obmen_peremesheniem(Massiv[1], Massiv[8]);

    for(int i = 0; i < KOL; i++){
        Massiv[i].Show();
        cout << endl;
    }

    return 0;
}
