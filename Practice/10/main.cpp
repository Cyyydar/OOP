#include <iostream>
#include "Matrix.h"
#include "Solve.h"

int main()
{
    Solve M;

    M.create();
    M.show();

    M.solve();

    return 0;
}
