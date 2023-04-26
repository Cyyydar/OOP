#include "createArray.h"
#include "deleteArray.h"
#include "show.h"
#include "sorting.h"
#include "zeroingArray.h"

#include <iostream>

int main()
{
    int*arr{nullptr};
    int sizeArr{0};
    createArray(arr, sizeArr);
    showArray(arr, sizeArr);
    sortingArray(arr, sizeArr);
    showArray(arr, sizeArr);
    zeroingArray(arr, sizeArr);
    showArray(arr, sizeArr);
    deleteArray(arr, sizeArr);
    return 0;
}
