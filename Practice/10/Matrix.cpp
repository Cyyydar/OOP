#include <iostream>
#include "Matrix.h"

using namespace std;

void Matrix::create(){
    if(Mas != nullptr){
        int c;
        cout << " massiv ne bil sozdan\n vvedite novi - 1\n ostavit - 0";
        cin >> c;
        if (c == 0) {
            return;
        }
        for(int i = 0; i < K; i++){
            delete[]Mas[i];
        }
        delete[]Mas;
    }
    K = 3;
    N = 3;
    Mas = new int*[K];
    for(int i = 0; i < K; i++){
        Mas[i] = new int[N];
    }
    cout << "Vvedite elementi massiva: celochislennuy matrix razmerom " << K << "x" << N << "\n";
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cin >> Mas[i][j];
        }
    }
}

void Matrix::show() const{
    if(Mas == nullptr){
        cout << "Massiv ne bil sozdan\n";
        return;
    }
    cout << "Matrix:\n";
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cout << Mas[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::Mswap(int i, int j, int k, int m){
    int temp = Mas[i][j];
    Mas[i][j] = Mas[k][m];
    Mas[k][m] = temp;
}

int Matrix::xsum(int c, int r){
    int sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i != c && j != r){
                sum += Mas[i][j];
            }
        }
    }
    return sum;
}
