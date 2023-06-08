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
        if (k > 0 && m > 0){
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
        if (k <= 0 || m <= 0){
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

    dinMas(dinMas &other){
		if((other.mas != nullptr) && (other.K != 0) && (other.M != 0)){
			K = other.K;
			M = other.K;
			mas = new float*[K];
			
			for(int i = 0; i < K; i++){
				mas[i] = new float[M];
			}
			for(int i = 0; i < K; i++){
				for(int j = 0; j < M; j++){
					mas[i][j] = other.mas[i][j];
				}
			}
		}
    }
    dinMas& operator=(dinMas &other) {
        if(this == &other){
            return *this;
        }
        delMas();

		if((other.mas != nullptr) && (other.K != 0) && (other.M != 0)){
			K = other.K;
			M = other.K;
			mas = new float*[K];
			
			for(int i = 0; i < K; i++){
				mas[i] = new float[M];
			}
			for(int i = 0; i < K; i++){
				for(int j = 0; j < M; j++){
					mas[i][j] = other.mas[i][j];
				}
			}
		}
        return *this;
    }
    dinMas(dinMas &&other) {
		if((other.mas != nullptr) && (other.K != 0) && (other.M != 0)){
			K = other.K;
			M = other.M;
			mas = other.mas;
			other.mas = nullptr;
			other.K = 0;
			other.M = 0;
		}
    }
    dinMas& operator=(dinMas &&other){
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

};

void shift(dinMas*& mas, int Size, int s){
    if (s == 0)
        return;
    dinMas temp[Size];
    if(s < 0) {
        s = Size + s;
    }
    for(int i = 0; i < Size; i++){
        temp[i] = move(mas[i]);
    }
    for(int i = 0; i < Size; i++){
        mas[(i+s)%Size] = move(temp[i]);
    }
    return;
}

int main()
{
    dinMas* mas = nullptr;
    int cnt = 4;
    cout << "Enter count of arrays: ";
    cin >> cnt;
    mas = new dinMas[cnt];
    cout << "Arrays filling by mas[i].fillMas(i,count, i*3)\n";
    cout << " fillMas(K,M,g) is matrix KxM. Filling by mas[i][j] = g/(i+j+1)\n";
    for(int i = 0; i < cnt; i++){
        mas[i].fillMas(i,cnt,i*3);
    }

    for(int i = 0; i < cnt; i++){
        cout << "\tArray N " << i << "\n";
        mas[i].show();
        cout<< "-------\n";
    }
    cout << "Enter magnitude of shift: ";
    int sh;
    cin >> sh;
    shift(mas, cnt, sh);
    cout << "\nResult shifting:\n\n";
    for(int i = 0; i < cnt; i++){
        cout << "\tArray N " << i << "\n";
        mas[i].show();
        cout<< "-------\n";
    }
    return 0;
}
