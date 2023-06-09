#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
private:
    int K = 0;
    int N = 0;
    int** Mas = nullptr;
public:
    Matrix();
    ~Matrix();
    int* operator[](const int i) const;
    void create();
    void show() const;
    void Mswap(int i, int j, int k, int m);
    int xsum(int c, int r);
};

#endif // MATRIX_H
