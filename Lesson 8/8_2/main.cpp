#include <iostream>

void createArray(int*&, int&);
void showArray(const int*, const int);
void sortingArray(int* const, const int);
void deleteArray(int*&, int&);

int main()
{
    int*arr{nullptr};
    int sizeArr{0};
    createArray(arr, sizeArr);
    showArray(arr, sizeArr);
    sortingArray(arr, sizeArr);
    showArray(arr, sizeArr);
    deleteArray(arr, sizeArr);
    return 0;
}
