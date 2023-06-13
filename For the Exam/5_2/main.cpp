#include <iostream>
#include <fstream>
#include <cstdio>
#include <limits>

using namespace std;

class dinMas
{
protected:
    string address = "out.txt";
    float* mas = nullptr;
    int sizeMas = 0;
public:
    dinMas(): address{"out.txt"}, mas {nullptr}, sizeMas {0} {}
    dinMas(int s, float e, float g){
        if(s > 0){
            mas = new float[s];
            sizeMas = s;
            for(int i = 0; i < sizeMas; i++){
                mas[i] = ((e + i) * (g - i))/(i + 1);
            }

            ofstream fout {address};
            fout << sizeMas << endl;
            for(int i = 0; i < sizeMas; i++){
                fout << mas[i] << " ";
            }
            fout.close();
        } else {
            if (remove(address.c_str()) != 0){
                cerr << "File was not removed";
            }
        }
    }

    ~dinMas() {
        delete[] mas;
        mas = nullptr;
        sizeMas = 0;
    }

    void show() const {
        if(mas == nullptr){
            cout << "Array is not created\n";
            return;
        }
        cout << "Array: \n";
        for(int i = 0; i < sizeMas; i++){
            cout << mas[i] << " ";
        }
        cout << endl;
    }

    dinMas(const dinMas& other) = delete;
    dinMas& operator=(const dinMas& other) = delete;
    dinMas(dinMas&& other) = delete;
    dinMas& operator=(dinMas&& other) = delete;
};

class overWriting: public dinMas{
private:
    int getint(){
        while(1){
            int a = 0;
            cout << "Enter integer number: \n";
            cin >> a;

            if(cin.fail()){
                cout << "Error, try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(cin.peek() != '\n'){
                cout << "Error, try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
    double getdouble(){
        while(1){
            double a = 0;
            cout << "Enter integer number: \n";
            cin >> a;

            if(cin.fail()){
                cout << "Error, try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if(cin.peek() != '\n'){
                cout << "Error, try again\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return a;
        }
    }
public:
    overWriting(int s, float e, float g): dinMas(s, e, g) {}

    void write(){

        while(1){
            delete mas;
            mas = nullptr;
            cout << "Enter new size of array:\n";
            sizeMas = getint();

            mas = new float[sizeMas];

            cout << "Fill array ( size =" << sizeMas << ")\n";
            for(int i = 0; i < sizeMas; i++){
                cout << "[" << i << "] ";
                mas[i] = getdouble();
            }

            cout << "Check the correctness:\n";
            show();
            cout << "Right? (1 - yes)";
            if(getint() == 1){
                break;

            }
        }
        ofstream fout {address};
        fout << sizeMas << endl;
        for(int i = 0; i < sizeMas; i++){
            fout << mas[i] << " ";
        }
    }

};


int main()
{
    dinMas mas(3, 3.13, -1);
    mas.show();
    overWriting ov(25,3,1);
    ov.write();

    return 0;
}
