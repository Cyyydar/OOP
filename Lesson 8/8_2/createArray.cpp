#include <iostream>

void createArray(int*& arr, int& sizeArr){
    //deleteArray(arr, sizeArr);
    delete[] arr;
    arr = nullptr;
    sizeArr = 0;

    std::cout << "Enter array size: ";
    int a;
    std::cin >> a;
    if(a<1){
        std::cout << "Invalid size\n";
        std::cout << "Array is not created\n";
        return;
    }

    sizeArr = a;
    arr = new int[sizeArr];

    std::cout << "Please fill my array, sempai UwU \n";
    for(int i = 0; i < sizeArr; i++){
        std::cin >> arr[i];
    }
}
