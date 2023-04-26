#include <iostream>

void showArray(const int* arr, const int arrSize){
    if(arr == nullptr){
        std::cout << "Array is not created\n";
        return;
    }

    std::cout << "Array:\n";

    for(int i = 0; i < arrSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}
