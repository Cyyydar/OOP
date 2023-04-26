#include <iostream>

void printArray(float** arr, const int A, const int B){
    if(arr == nullptr){
        std::cout << "Array is not created\n";
        return;
    }

    std::cout << "Array:\n";
    for(int i = 0; i < A; i++){
        for(int j = 0; j < B; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
