#include <iostream>

using namespace std;

class dinMas {
    float** mas = nullptr;
    int K = 0;
    int M = 0;

    void delMas(){
        for(int i = 0; i < K; i++){
            delete[] mas[i];
        }
        delete[] mas;
        mas = nullptr;
        K = 0;
        M = 0;
    }

    float exp(float e, int s){
        float result = 1;
        for(int i = 0; i < s; i++){
            result *= e;
        }
        return result;
    }

public:
    dinMas(): mas {nullptr}, K {0}, M {0} {}
    dinMas(int k, int m, float g): mas {nullptr}, K {0}, M {0} {
        if((k > 0) && (m > 0)){
            K = k;
            M = m;
            mas = new float*[K];
            for(int i = 0; i < K; i++){
                mas[i] = new float [M];
            }

            for(int i = 0; i < K; i++){
                for(int j = 0; j < M; j++){
                    mas[i][j] = (exp(g,(i+j+1))/(i+j+2));
                }
            }
        }
    }

    ~dinMas(){
        delMas();
    }

    dinMas(const dinMas& other): mas {nullptr}, K {0}, M {0} {
        if((other.mas != nullptr) && (other.K != 0) && (other.M != 0)){
            K = other.K;
            M = other.M;
            mas = new float*[K];
            for(int i = 0; i < K; i++){
                mas[i] = new float [M];
            }

            for(int i = 0; i < K; i++){
                for(int j = 0; j < M; j++){
                    other.mas[i][j] = mas[i][j];
                }
            }
        }
    }

    dinMas& operator=(dinMas& other) {
        delMas();
        if(this == &other){
            return *this;
        }
        if((other.mas == nullptr) && (other.K == 0) && (other.M == 0)){
            return *this;
        }
        K = other.K;
        M = other.M;
        mas = new float*[K];
        for(int i = 0; i < K; i++){
            mas[i] = new float [M];
        }

        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                other.mas[i][j] = mas[i][j];
            }
        }
        return *this;
    }

    dinMas(dinMas&& other): mas {nullptr}, K {0}, M {0} {
        if((other.mas != nullptr) && (other.K != 0) && (other.M != 0)){
            K = other.K;
            M = other.M;
            mas = other.mas;
            other.mas = nullptr;
            other.K = 0;
            other.M = 0;
        }
    }
    dinMas& operator=(dinMas&& other) {
        if(this == &other){
            return *this;
        }
        delMas();
        if((other.mas != nullptr) && (other.K != 0) && (other.M != 0)){
            K = other.K;
            M = other.M;
            mas = other.mas;
            other.mas = nullptr;
            other.K = 0;
            other.M = 0;
        }
        return *this;
    }


    void fillMas(int k, int m, float g){
        delMas();
        if((k <= 0) && (m <= 0)){
            return;
        }
        K = k;
        M = m;
        mas = new float*[K];
        for(int i = 0; i < K; i++){
            mas[i] = new float [M];
        }

        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                mas[i][j] = (exp(g,(i+j+1))/(i+j+2));
            }
        }
        return;
    }

    void show() const {
        if(mas == nullptr){
            cout << "Array is not created\n";
            return;
        }
        cout << "Array: \n";
        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                cout << mas[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    float sum() const {
        float sum = 0;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                sum += mas[i][j];
            }
        }
        return sum;
    }
};

void sortMas(dinMas*& mas){
    for(int i = 6; i > 0; i--){
        for(int j = 1; j < i; j++){
            if( mas[j].sum() < mas[j-1].sum()){
                dinMas temp = move(mas[j]);
                mas[j] = move(mas[j-1]);
                mas[j-1] = move(temp);
            }
        }
    }
}

int main()
{
    dinMas* mas = nullptr;
    mas = new dinMas[6];
    for(int i = 0; i < 6; i++){
        mas[i].fillMas(i,i+2,-1);
        cout << "Mas N " << i << endl;
        mas[i].show();
    }

    sortMas(mas);
    cout << "\n\nSorted mas:\n\n";

    for(int i = 0; i < 6; i++){
        cout << "Mas N " << i << " sum = " << mas[i].sum() << endl;
        mas[i].show();
    }
    return 0;
}
