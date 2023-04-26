void deleteArray(float**& arr, int A, int B){
    for(int i = 0; i < A; i++){
        delete[]arr[i];
    }
    delete[]arr;
    arr = nullptr;
    A = 0;
    B = 0;
}
