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

    dinMas(const dinMas& other) = delete;
    dinMas& operator=(dinMas& other) = delete;
    dinMas(dinMas&& other) = delete;
    dinMas& operator=(dinMas&& other) = delete;


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

int main()
{
    dinMas mas(2,3,4);
    mas.show();
    cout << "sum = " << mas.sum() << endl;

    return 0;
}
