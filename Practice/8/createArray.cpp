#include <iostream>

void createArray(float**& arr, int& A, int& B){
    //deleteArray(arr, sizeArr);
    for(int i = 0; i < A; i++){
            delete[]arr[i];
        }
    delete[]arr;
    arr = nullptr;

    A = 0;
    B = 0;

    int a;
    int b;
    std::cout << "Enter count of strings: ";
    std::cin >> a;
    if(a<1){
        std::cout << "Invalid size\n";
        std::cout << "Array is not created\n";
        return;
    }

    std::cout << "Enter count of column: ";
    std::cin >> b;
    if(b<1){
        std::cout << "Invalid size\n";
        std::cout << "Array is not created\n";
        return;
    }
    A = a;
    B = b;

    arr = new float*[A];
    for(int i = 0; i < A; i++){
        arr[i] = new float [B];
    }

    std::cout << "Please, fill matrix (float)\n";
    for(int i = 0; i < A; i++){
        for(int j = 0; j < B; j++){
            std::cin >> arr[i][j];
        }
    }
}
