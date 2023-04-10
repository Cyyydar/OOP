#include <iostream>

using namespace std;


class DinMas2{

    int **Mas = nullptr;
    int K = 0;
    int S = 0;

    int sum() const {
        int temp = 0;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < S; j++){
                temp += Mas[i][j];
            }
        }
        return temp;
    }

    void copyMas(const DinMas2 &ob){
        if((ob.Mas != nullptr) && ((ob.K != 0) || (ob.S != 0))){
            K = ob.K;
            S = ob.S;
            Mas = new int*[K];
            for(int i = 0; i < ob.K; i++){
                Mas[i] = new int[S];
            }

            for(int i = 0; i < ob.K; i++){
                for(int j = 0; i < ob.S; j++){
                    Mas[i][j] = ob.Mas[i][j];
                }
            }
        }
    }

    void moveMas(DinMas2 &ob){
        K = 0;
        S = 0;
        if((ob.Mas != nullptr) && ((ob.K != 0) || (ob.S != 0))){
            Mas = ob.Mas;
            K = ob.K;
            S = ob.S;
            ob.Mas = nullptr;
            ob.K = 0;
            ob.S = 0;
        }
    }

    void deleteMas(){
        for(int i = 0; i < S; i++){
            delete[]Mas[i];
        }
        delete[]Mas;
        Mas = nullptr;
    }

public:
    DinMas2(const DinMas2 &ob): Mas{nullptr}, K{0}, S{0} {
        copyMas(ob);
        cout << "\n Constructor kopirovaniya \n";
    }

    DinMas2& operator=(const DinMas2 &ob){
        if(this == &ob)
            return *this;
        deleteMas();
        Mas = nullptr;
        S = 0;
        K = 0;
        copyMas(ob);
        cout << "\n Pereopredelennoe prisvoenie \n";
        return *this;
    }

    DinMas2(DinMas2&&ob): Mas{nullptr}, K{0}, S{0} {
        moveMas(ob);
        cout << "\n Kopirovanie peremesheniem \n";
    }

    DinMas2&operator=(DinMas2 &&ob){
        if(this == &ob)
            return *this;
        deleteMas();
        moveMas(ob);
        cout << "\n Pereopredelennoe prisvoenie peremesheniem \n";
        return *this;
    }

    DinMas2(int k, int s, int m): Mas{nullptr}, K{0}, S{0} {
        cout << "\n Konstructor s parametrami \n";
        if(k < 1)
            return;
        K = k;
        S = s;
        Mas = new int*[K];
        for(int i = 0; i < K; i++){
            Mas[i] = new int[S];
        }
        for(int i = 0; i < K; i++){
            for(int j = 0; j < S; j++){
                Mas[i][j] = m;
            }
        }
    }

    DinMas2(): Mas{nullptr}, S{0}, K{0} {
        cout << "\n Konstructor bez parametrov \n";
    }

    ~DinMas2(){
        deleteMas();
        cout << "\n Destructor porabotal";
    }

    void Create (){
        if(Mas != nullptr) {
            cout << " Massiv uje zadan";
            for(int i = 0; i < K; i++)
                for(int j = 0; j < S; j++)
                    cout << " " << Mas[i][j];
            cout << "\n Chtobi perezapisat vvedi - 1\n";
            cout << " Chtobi ne perezapisat vvedite - 0\n";
            int f;
            cin >> f;
            if(f == 0)
                return;
        }
        deleteMas();
        cout << "Vvedite razmer massiva (celoe chislo bolshe 0): ";
        cin >> K;
        Mas = new int*[K];
            for(int i = 0; i < K; i++){
                Mas[i] = new int[S];
            }
        cout << "Vvodite celie chisla: \n";
        for(int i = 0; i < K; i++) {
            for(int j = 0; j < S; j++){
                cout << " Mas [" << i << "][" << j << "]= ";
                cin >> Mas[i][j];
            }
        }
        cout << " Vvod zavershon \n";
    }

    void Show() const{
        if(Mas == nullptr){
            cout << " Massiv ne bil zadan \n";
            return;
        }
        cout << "\n Vivod massiva: \n";
        for(int i = 0; i < K; i++) {
            for(int j = 0; j < S; j++){
                cout << " " << Mas[i][j];
            }
            cout << endl;
        }
        cout << "\n Adress nachala massiva: " << Mas << endl;
    }

    friend bool operator==(const auto&ob1, const auto&ob2);
    friend bool operator!=(const auto&ob1, const auto&ob2);
    friend bool operator>(const auto&ob1, const auto&ob2);
    friend bool operator>=(const auto&ob1, const auto&ob2);
    friend bool operator<(const auto&ob1, const auto&ob2);
    friend bool operator<=(const auto&ob1, const auto&ob2);
};

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

    friend bool operator==(const auto&ob1, const auto&ob2);
    friend bool operator!=(const auto&ob1, const auto&ob2);
    friend bool operator>(const auto&ob1, const auto&ob2);
    friend bool operator>=(const auto&ob1, const auto&ob2);
    friend bool operator<(const auto&ob1, const auto&ob2);
    friend bool operator<=(const auto&ob1, const auto&ob2);

};

int main()
{
    DinMas Massiv1(6, 6);
    cout << "\n Massive1: \n";
    Massiv1.Show();


    DinMas2 Massiv2(10, 10, 1);
    cout << "\n Massive2: \n";
    Massiv2.Show();

    cout << "Massiv1 == Massiv2 " << (Massiv1 == Massiv2) << endl << endl;


    cout << "Massiv1 > Massiv2 " << (Massiv1 > Massiv2) << endl;
    cout << "Massiv1 >= Massiv2 " << (Massiv1 >= Massiv2) << endl;
    cout << "Massiv1 < Massiv2 " << (Massiv1 < Massiv2) << endl;
    cout << "Massiv1 <= Massiv2 " << (Massiv1 <= Massiv2) << endl << endl;

    cout << "Massiv1 < Massiv2 " << (Massiv1 < Massiv2) << endl;
    cout << "Massiv1 <= Massiv2 " << (Massiv1 <= Massiv2) << endl;

    return 0;
}


bool operator==(const auto&ob1, const auto&ob2){
    if(ob1.sum() == ob2.sum())
        return true;
}

bool operator!=(const auto&ob1, const auto&ob2){
    return !(ob1 == ob2);
}

bool operator>(const auto&ob1, const auto&ob2){
    if(ob1.sum() > ob2.sum())
        return true;
    return false;
}

bool operator>=(const auto&ob1, const auto&ob2){
    if(ob1.sum() >= ob2.sum())
        return true;
    return false;
}

bool operator<(const auto&ob1, const auto&ob2){
    if(ob1.sum() < ob2.sum())
        return true;
    return false;
}

bool operator<=(const auto&ob1, const auto&ob2){
    if(ob1.sum() <= ob2.sum())
        return true;
    return false;
}
