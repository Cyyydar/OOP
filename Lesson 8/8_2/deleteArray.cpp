void deleteArray(int*& arr, int& sizeArr){
    delete[] arr;
    arr = nullptr;
    sizeArr = 0;
}
