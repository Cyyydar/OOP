#include <iostream>
#include <fstream>

int main()
{
    // Мы передадим флаг ios::app, чтобы сообщить ofstream о необходимости добавления
    // вместо того, чтобы перезаписывать файл. Нам не нужно передавать std::ios::out,
    // поскольку std::ios::out для ofstream используется по умолчанию
    std::ofstream outf{ "file.fff", std::ios::app };

    // Если мы не смогли открыть выходной файловый поток для записи
    if (!outf)
    {
        // Распечатываем ошибку и выходим
        std::cerr << "Uh oh, Sample.dat could not be opened for writing!\n";
        return 1;
    }

    outf << "This is line 3" << '\n';

    return 0;

    // Когда outf выходит из области видимости,
    // деструктор ofstream закроет файл
}
