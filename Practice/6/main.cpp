// конструктор перемещения и оператор перемещения присвоением
#include <iostream>

using namespace std;

class DinMas{

    int **Mas = nullptr;
    int K = 0;
    int S = 0;

    void copyMas(const DinMas &ob){
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

    void moveMas(DinMas &ob){
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
    DinMas(const DinMas &ob): Mas{nullptr}, K{0}, S{0} {
        copyMas(ob);
        cout << "\n Constructor kopirovaniya \n";
    }

    DinMas& operator=(const DinMas &ob){
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

    DinMas(DinMas&&ob): Mas{nullptr}, K{0}, S{0} {
        moveMas(ob);
        cout << "\n Kopirovanie peremesheniem \n";
    }

    DinMas&operator=(DinMas &&ob){
        if(this == &ob)
            return *this;
        deleteMas();
        moveMas(ob);
        cout << "\n Pereopredelennoe prisvoenie peremesheniem \n";
        return *this;
    }

    DinMas(int k, int s, int m): Mas{nullptr}, K{0}, S{0} {
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

    DinMas(): Mas{nullptr}, S{0}, K{0} {
        cout << "\n Konstructor bez parametrov \n";
    }

    ~DinMas(){
        delete[]Mas;
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

    friend DinMas operator+(const DinMas &ob1, const DinMas &ob2);
};

int main()
{
    DinMas ob1{4, 4, 4};
    DinMas ob2{10, 10, 10};
    DinMas ob3;
    ob3 = ob1 + ob2;
    ob3.Show();

    return 0;
}

DinMas operator+(const DinMas &ob1, const DinMas &ob2){
    cout << "Operator + nachal rabotu\n";
    DinMas ob3;
    if((ob1.K == 0) || (ob1.S == 0) || (ob2.K == 0) || (ob2.S == 0)){
        return ob3;
    }

    ob3.S = max(ob1.S, ob2.S);
    ob3.K = max(ob1.K, ob2.K);


    ob3.Mas = new int*[ob3.K];
    for(int i = 0; i < ob3.K; i++){
        ob3.Mas[i] = new int[ob3.S];
    }

    cout << "\nmama\n";
    for(int i=0; i < ob1.S; i++){
        for(int j=0; j < ob1.K; j++){
            ob3.Mas[i][j] = ob1.Mas[i][j];
        }
    }

    for(int i=0; i < ob2.S; i++){
        for(int j=0; j < ob2.K; j++){
            ob3.Mas[i][j] += ob2.Mas[i][j];
        }
    }

    cout << "Operator+ zakonchil rabotu";
    return ob3;
}
