#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class dinMas
{
private:
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
        delete mas;
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


int main()
{
    dinMas mas(3, 3.13, -1);
    mas.show();
    dinMas mas1;
    mas1.show();
    return 0;
}
