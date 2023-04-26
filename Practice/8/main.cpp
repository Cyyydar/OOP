#include <iostream>

using namespace std;

void createArray(float**&, int&, int& );
void deleteArray(float**&, int, int);
void printArray(float**, const int, const int B);
float** multiple(float**&, const int, const int, float**&, const int, const int);

int main()
{
    int A1 = 0;
    int B1 = 0;
    float** arr1 = nullptr;

    createArray(arr1, A1, B1);
    printArray(arr1 ,A1 ,B1);

    int A2 = 0;
    int B2 = 0;
    float** arr2 = nullptr;

    createArray(arr2, A2, B2);
    printArray(arr2 ,A2 ,B2);

    multiple(arr1, A1, B1, arr2, A2, B2);



    return 0;
}
