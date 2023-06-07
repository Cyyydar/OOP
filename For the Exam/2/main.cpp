#include <iostream>

using namespace std;

class dinMas {
    float** mas;
    int K, M;

    void delMas(){
        if(mas == nullptr){
            K = 0;
            M = 0;
            return;
        }

        for(int i = 0; i < K; i++){
            delete[]mas[i];
        }
        delete[]mas;

        K = 0;
        M = 0;
        mas = nullptr;
    }
public:
    dinMas(){
        mas = nullptr;
        K = 0;
        M = 0;
    }
    dinMas(int k, int m, float g): mas {nullptr}, K {0}, M {0} {
        if (k > 0 || m > 0){
            mas = new float*[k];
            for(int i = 0; i < k; i++){
                mas[i] = new float[m];
            }
            this->K = k;
            this->M = m;
            for(int i = 0; i < K; i++){
                for(int j = 0; j < M; j++){
                    mas[i][j] = g/(i+j+1);
                }
            }
        }
    }

    void show() const {
        if(mas == nullptr){
            cout << "Array is not created\n";
            return;
        }
        cout << "Your array:\n";
        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                cout << mas[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void fillMas(int k, int m, float g){
        delMas();
        if (k <= 0 && m <= 0){
            return;
        }
        mas = new float*[k];
        for(int i = 0; i < k; i++){
            mas[i] = new float[m];
        }
        this->K = k;
        this->M = m;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                mas[i][j] = g/(i+j+1);
            }
        }
    }

    float sum(){
        float sum = 0;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                sum += mas[i][j];
            }
        }
        return sum;
    }

    ~dinMas(){
        delMas();
    }
    dinMas(dinMas &other) = delete;
    dinMas& operator=(dinMas &other) = delete;
    dinMas(dinMas &&other) = delete;
    dinMas& operator=(dinMas &&other) = delete;

};

int main()
{
    dinMas ob;
    ob.show();
    ob.fillMas(2,3,4);
    ob.fillMas(4,3,2);
    ob.show();
    cout << ob.sum();

    return 0;
}
