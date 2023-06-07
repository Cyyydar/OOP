#include <iostream>

using namespace std;

class dinMas{
public:
    int sizeMas;
    float* mas;
public:
    dinMas(){
        sizeMas = 0;
        mas = nullptr;
    };
    dinMas(int s, float e, float g){
        if(s > 0){
            mas = new float[s];
            sizeMas = s;
            cout << s << " " << e << " " << g << " " << sizeMas << "\n" ;
            for(int i = 0; i < s; i++){
                mas[i] = ((e+i)*(g-i))/(i+1);
            }
        }
    }
    ~dinMas(){
        delete mas;
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

class dinIndex: public dinMas{
public:
    dinIndex(){}
    dinIndex(int s, float e, float g): dinMas(s,e,g){

    }
    ~dinIndex(){}
    float& operator[](const int i){
        if (mas != nullptr && i < sizeMas && i >= 0)-
            return mas[i];
        throw new string("invalid array index");
    }
};

int main()
{
    dinIndex ob3;
    ob3.show();
    dinIndex ob1(5,3.14,-3);
    dinIndex ob2(2,2,4);
    ob1.show();
    ob2.show();
    try{
        cout << ob1[5] << endl;
        ob1[2] = -3.14;
        cout << ob1[2] << endl;
        cout << ob3[-1] << endl;
    }
    catch(string *err) {
        cerr << "Error: " << *err << ", program crashes " << endl;
        return 1;
    }
    return 0;
}
