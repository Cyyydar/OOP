#include "Solve.h"

Solve::Solve()
{
    //ctor
}

Solve::~Solve()
{
    //dtor
}

void Solve::solve(){
    int max = 0;

    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            int temp = xsum(i,j);
            if(temp > max){
                max = temp;
                Mswap(i, j, 2, 2);
            }
        }
    }
}
