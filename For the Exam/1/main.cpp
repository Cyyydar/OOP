#include <iostream>

using namespace std;

class dinMas{
protected:
    int sizeMas = 0;
    float* mas = nullptr;
public:
    dinMas(){};
    dinMas(int s, float e, float g){
        if(s > 0){
            mas = new float[s];
            sizeMas = s;
            for(int i = 0; i < s; i++){
                mas[i] = ((e+i)*(g-i))/(i+1);
            }
        } else {
            mas = nullptr;
            sizeMas = 0;
        }
    }
    ~dinMas(){
        delete[] mas;
        mas = nullptr;
        sizeMas = 0;
    }

    dinMas(const dinMas &ob) = delete;
    dinMas& operator=(const dinMas &ob) = delete;
    dinMas(const dinMas &&ob) = delete;

    void show() const{
        if(sizeMas == 0 || mas == nullptr){
            cout << "Array is not created\n";
            return;
        }
        cout << "Array:\n";
        for(int i = 0; i < sizeMas; i++){
            cout << mas[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    dinMas ob3;
    ob3.show();
    dinMas ob1(5,3.14,-3);
    dinMas ob2(2,2,4);
    ob1.show();
    ob2.show();
    return 0;
}
