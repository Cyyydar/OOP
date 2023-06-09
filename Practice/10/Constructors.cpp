#include "Matrix.h"
Matrix::Matrix():Mas{nullptr}, K{0},N{0}{}

Matrix::~Matrix(){
    for(int i = 0; i < K; i++){
        delete[]Mas[i];
    }
    delete[]Mas;
}

int* Matrix::operator[](const int i) const {
        return Mas[i];
}
