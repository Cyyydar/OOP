#include <iostream>
#include <fstream>


int main()
{
    std::ifstream fin{"input.txt"};

    if (!fin){
        std::cerr << "input.txt is unavalible";
        return 1;
    }

    float Array[99999];
    int len = 0;

    while(fin){
        fin >> Array[len];
        len++;
    }
    len--;


    for(int i = len; i > 0; i--){
        for(int j = 1;j < i-1;j++){
            if(Array[j-1] > Array[j]){
                float temp = Array[j];
                Array[j] = Array[j-1];
                Array[j-1] = temp;
            }
        }
    }

    std::ofstream fout{"output.txt"};

    if (!fout){
        std::cerr << "output.txt is unavalible";
        return 1;
    }

    for(int i = 0; i < len; i++){
        fout << Array[i] << " ";
    }

    return 0;
}
