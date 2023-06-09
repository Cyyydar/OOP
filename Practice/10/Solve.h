#ifndef SOLVE_H
#define SOLVE_H

#include <Matrix.h>


class Solve : public Matrix
{
private:

public:
    Solve();
    ~Solve();
    void solve();
    void Cswap(int i, int j);
};

#endif // SOLVE_H
