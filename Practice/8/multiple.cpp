#include <iostream>

void multiple(float**& arr1, const int A1, const int B1, float**& arr2, const int A2, const int B2){
    if(arr1 == nullptr && arr2 == nullptr){
        std::cout << "Massive is not exist!\n";
        return;
    }
    if( B1 != A2){
        std::cout << "Invalid matrix\n";
        return;
    }
    int rA = A1;
    int rB = B2;
    float** res = nullptr;
    res = new float*[rA];

    for(int i = 0; i < rA; i++){
        res[i] = new float[rB];
    }


    for (int i = 0; i < rA; i++){
        for(int j = 0; j < rB; j++){
            float sum = 0;
            for (int k = 0; k < B1; k++){

                sum += arr1[i][k] * arr2[k][j];
            }
            res[i][j] = sum;
        }
    }

    std::cout << "Result:\n";
    for(int i = 0; i < rB; i++){
        for(int j = 0; j < rA; j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
