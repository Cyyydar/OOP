#include <iostream>

using namespace std;

class dinMas{
private:
    int exp(float e, int s){
        float result = 1;
        for(int i = 0; i < s; i++){
            result *= e;
        }
        return result;
    }

    void delMas(){
        delete mas;
        mas = nullptr;
        sizeMas = 0;
    }

protected:
    float* mas = nullptr;
    int sizeMas = 0;
public:
    dinMas(): mas{nullptr}, sizeMas{0} {}
    dinMas(int k, float e, float g): mas{nullptr}, sizeMas{0} {
        if(k > 0){
            mas = new float[k];
            sizeMas = k;
            for(int i = 0; i < sizeMas; i++){
                mas[i] = exp(e,(i+2)) + exp(g,(i+3));
            }
        }
    }

    ~dinMas(){
        delMas();
    }

    void fillMas(int k, float e, float g){
        delMas();
        if(k <= 0){
            return;
        }
        mas = new float[k];
        sizeMas = k;
        for(int i = 0; i < sizeMas; i++){
            mas[i] = exp(e,(i+2)) + exp(g,(i+3));
        }
    }

    void show() const {
        if(mas == nullptr){
            cout << "Array is not created\n";
            return;
        }
        cout << "Array:\n";
        for(int i = 0; i < sizeMas; i++){
            cout << mas[i] << " ";
        }
        cout << endl;
    }

    dinMas(const dinMas& other){
        if((other.mas != nullptr) &&(other.sizeMas != 0)){
            sizeMas = other.sizeMas;
            mas = new float[sizeMas];
            for(int i = 0; i < sizeMas; i++){
                mas[i] = other.mas[i];
            }
        }
    }

    dinMas(dinMas&& other) {
        if((other.mas != nullptr) &&(other.sizeMas != 0)){
            sizeMas = other.sizeMas;
            mas = other.mas;
            other.mas = nullptr;
            other.sizeMas = 0;
        }
    }

    dinMas& operator=(const dinMas& other) {
        if(this == &other){
            return *this;
        }
        delMas();
        if((other.mas != nullptr) &&(other.sizeMas != 0)){
            sizeMas = other.sizeMas;
            mas = new float[sizeMas];
            for(int i = 0; i < sizeMas; i++){
                mas[i] = other.mas[i];
            }
        }
        return *this;
    }

    dinMas& operator=(dinMas&& other) {
        if(this == &other){
            return *this;
        }
        delMas();
        if((other.mas != nullptr) &&(other.sizeMas != 0)){
            sizeMas = other.sizeMas;
            mas = other.mas;
            other.mas = nullptr;
            other.sizeMas = 0;
        }
        return *this;
    }
};

int main()
{
    dinMas ob1;
    ob1.show();
    ob1.fillMas(-4,10,-2);
    ob1.show();
    ob1.fillMas(4,10,-2);
    ob1.show();
    dinMas ob2(ob1);
    ob2.show();
    dinMas ob3(move(ob2));
    ob2.show();
    ob3.show();
    return 0;
}
