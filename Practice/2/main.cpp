// Класс, реализующий динамичкский двумерный массив
#include <iostream>

using namespace std;

class DM{
    protected:
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

void createAndFill(){
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

    void create(int w,int h){
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


        if(h < 1) {
            cout << " razmer massiva ne mojet bit menshe 1 - massiv ne sozdan\n";
            return;
        }

        if(w < 1){
            cout << "Razmer massiva ne mojet bit menshe 1 - massiv ne sozdan\n";
            return;
        }
        K = h;
        N = w;
        Mas = new int*[K];
        for(int i = 0; i < K; i++){
            Mas[i] = new int[N];
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

class child : public DM {
    void matrixInArray(int* A){
        int Size = K;
        int k = 0;
        for (int i = 0;i < Size; i++){
            for (int j = 0; j < Size; j++){
                A[k] = Mas[i][j];
                k++;
            }
        }
    }

    void sortArray(int* A) {
        int Size = K;
        for (int i = Size*Size;i > 0; i--){
            for (int j = 1; j < i; j++){
                if(A[j-1] < A[j]){
                    int temp = A[j];
                    A[j] = A[j-1];
                    A[j-1] = temp;
                }
            }
        }
    }

public:
    child(int w, int h, int ph){
        create(w,h);
        for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++){
                Mas[i][j] = ph;
            }
        }
    }

    void spiralSort(){
        if (K != N){
            cout << "Ne kvadratnoya matritsa!\n";
            return;
        }
        int Size = K;
        int* Array = new int[Size*Size];
        matrixInArray(Array);
        sortArray(Array);

        int X, Y;
        // Center
        if(Size%2 != 0) {
            X = Size/2;
            Y = X;
        } else {
            X = Size/2;
            Y = X-1;
        }


        int k = 1;
        int j = 0;
        while(1){
            //down
            for(int i = 0; i < k; i++){
                if(X == Y && i < k && k != 1){
                    Mas[Y][X] = Array[j];
                    return;
                }
                Mas[Y][X] = Array[j];
                j++;
                Y++;
            }
            //left
            for(int i = 0; i < k; i++){
                Mas[Y][X] = Array[j];
                j++;
                X--;
            }
            k++;
            //up
            for(int i = 0; i < k; i++){
                if(X == Y && i < k && Y == 0){
                    Mas[Y][X] = Array[j];
                    return;
                }
                Mas[Y][X] = Array[j];
                j++;
                Y--;
            }
            //right
            for(int i = 0; i < k; i++){
                Mas[Y][X] = Array[j];
                j++;
                X++;
            }
            k++;
        }
    }

    int findMax() {
        int m = 0;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++){
                if (Mas[i][j] > m){
                    m = Mas[i][j];
                }
            }
        }
        return m;
    }

    int findMin() {
        int m = Mas[0][0];
        for(int i = 0; i < K; i++){
            for(int j = 0; j < N; j++){
                if (Mas[i][j] < m){
                    m = Mas[i][j];
                }
            }
        }
        return m;
    }

};

int main()
{
    child mas(3,4,7);
    mas.show();
    mas.createAndFill();
    mas.show();
    cout << "max: " << mas.findMax() << endl;
    cout << "min: " << mas.findMin() << endl;
    cout << "Spiral sort:\n";
    mas.spiralSort();
    mas.show();

    return 0;
}
