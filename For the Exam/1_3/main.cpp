#include <iostream>

using namespace std;

class dinMas{
private:
    int sizeMas = 0;
    float* mas = nullptr;
    int& counter(){
        static int c = 0;
        return c;
    }

public:

    dinMas(){++counter();};
    dinMas(int s, float e, float g){
        if(s > 0){
            mas = new float[s];
            sizeMas = s;
            for(int i = 0; i < s; i++){
                mas[i] = ((e+i)*(g-i))/(i+1);
            }
            ++counter();
        }
    }
    ~dinMas(){
        delete mas;
        mas = nullptr;
        sizeMas = 0;
        --counter();
    }

    dinMas(const dinMas &ob) = delete;
    dinMas& operator=(const dinMas &ob) = delete;
    dinMas(const dinMas &&ob) = delete;

    void getQuantity(){
        cout << "Instances exist: " << counter() << endl;
    }
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
    ob3.getQuantity();
    dinMas ob1(5,3.14,-3);
    dinMas ob2(2,2,4);
    ob1.getQuantity();
    ob2.getQuantity();
    ob1.show();
    ob2.show();
    return 0;
}
