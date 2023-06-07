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
    dinMas(const dinMas& other) = delete;
    dinMas(const dinMas&& other) = delete;
    dinMas& operator=(const dinMas& other) = delete;
    dinMas& operator=(const dinMas&& other) = delete;
};

int main()
{
    dinMas ob1;
    ob1.show();
    ob1.fillMas(-4,10,-2);
    ob1.show();
    ob1.fillMas(4,10,-2);
    ob1.show();
    return 0;
}
