// конструктор перемещения и оператор перемещения присвоением
#include <iostream>
#include <ctime>

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
        return *this;
    }

    DinMas(DinMas&&ob): Mas{nullptr}, RazMas{0} {
        if((ob.Mas != nullptr) && (ob.RazMas != 0)){
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr;
            ob.RazMas = 0;
        }
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

    unsigned int sTime = clock();


    for(long long i = 0; i < 99999999; i++){
        obmen_kopirovaniem(Massiv[i%10],Massiv[i%10]); //25
    }
    unsigned int eTime = clock();

    int cTime = (float)(eTime - sTime)/CLOCKS_PER_SEC;

    cout << "Копирование: " << cTime << endl;

    sTime = clock();

    for(long long i = 0; i < 99999999; i++){
        obmen_peremesheniem(Massiv[i%10], Massiv[i%10]); //6
    }

    eTime = clock();

    cout << "Перемещение: " << (float)(eTime - sTime)/CLOCKS_PER_SEC << endl;

    cout << "Разница: " << (float)cTime/(float)((float)(eTime - sTime)/CLOCKS_PER_SEC);
    return 0;
}
