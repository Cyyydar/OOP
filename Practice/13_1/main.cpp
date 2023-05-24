#include <iostream>
#include <fstream>
#include <cstdio>

class FileSystem{
    std::string address = "";

    int **Mas = nullptr;
    int K = 0;
    int M = 0;

public:
    FileSystem(std::string path){
        create(path);
    }

    void createMatrix(){
        std::cout << "Enter size of integer matrix(size is integer number > 0):\n";
        std::cin >> K;
        std::cin >> M;
        Mas = new int*[K];
        for(int i = 0; i < K; i++){
            Mas[i] = new int[M];
        }
        std::cout << "Fill integer matrix " << K << "x" << M << "\n";

        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                std::cout << "[" << i <<"][" << j << "] ";
                std::cin >> Mas[i][j];
            }
        }
    }

    void create(std::string path){
        del();

        address = path;
        std::ofstream fout {address};

        if(!fout){
            std::cerr << "Error: invalid address " << address << "\n";
        }
    }

    void del(){
        const char *temp = address.c_str();
        if(remove(temp) && address != ""){
            std::cerr << "Error: file " << address << " is not removed\n";
        }
    }

    void write(){
        std::ofstream fout {address};
        fout << K << " " << M << std::endl;
        for(int i = 0; i < K; i++){
            for(int j = 0; j < M; j++){
                fout << Mas[i][j] << " ";
            }
        fout << "\n";
        }

    }
};

int main()
{
    FileSystem file("text.txt");
    file.create("mama.txt");
    file.createMatrix();
    file.write();

    return 0;
}
