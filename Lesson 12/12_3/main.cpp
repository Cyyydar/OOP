#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::ofstream fout{"text.txt"};

    if (!fout){
        std::cerr << "text.txt is unavalible";
        return 1;
    }

    fout << "Pervaya stroka" <<" \n";
    fout << "Vtoraya stroka\n";
    return 0;
}
