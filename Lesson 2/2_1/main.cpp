// Класс, реализующий динамичкский двумерный массив
#include <iostream>

using namespace std;

class DM{
    int** Mas;
    int K, N;

    public:
    DM():Mas{nullptr}, K{0},N{0}{}
    ~DM(){
        for(int i = 0; i < K; i++){
            delete[]Mas[i];
        }
        delete[]Mas;
    }

    void create(){
        if(Mas != nullptr){
            int c;
            cout << " massiv ne bil sozdan\n vvedite novi - 1\n ostavit - 0";
            cin >> c;
            if (c == 0) {
                return;
            }
            for(int i = 0; i < K; i++){
                delete[]Mas[i];
            }
            delete[]Mas;
        }
        int a,b;

        cout << "Vvedite razmer massiva(celoe chislo bolshe 0): \n Kolichestvo strok = ";
        cin >> a;

        if(a < 1) {
            cout << " razmer massiva ne mojet bit menshe 1 - massiv ne sozdan\n";
            return;
        }

        cout << "kolichestvo stolbcov ravno ";
        cin >> b;
        if(b < 1){
            cout << "Razmer massiva ne mojet bit menshe 1 - massiv ne sozdan\n";
            return;
        }
        K = a;
        N = b;
        Mas = new int*[K];
        for(int i = 0; i < K; i++){
            Mas[i] = new int[N];
        }
        cout << "Vvedite elementi massiva: celochislennuy matrix razmerom" << K << "x" << N << "\n";
        for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++){
                cin >> Mas[i][j];
            }
        }
    }
    void show() const{
        if(Mas == nullptr){
            cout << "Massiv ne bil sozdan\n";
            return;
        }
        for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++){
                cout << Mas[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    DM mas;
    mas.show();
    mas.create();
    mas.show();
    mas.create();
    mas.show();
    return 0;
}
