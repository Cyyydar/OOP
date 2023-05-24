#include <iostream>
#include <fstream>

int main()
{
    std::ifstream fin{ "text.txt" };

    if (!fin)
    {
        std::cerr << "text.txt ne otkrilsa!" << std::endl;
        return 1;
    }
    while (fin)
    {
        std::string strInput;
        getline(fin, strInput); // считывает одну строку
        //fin >> strInput;
        std::cout << strInput << '\n';
    }
    return 0;
}
