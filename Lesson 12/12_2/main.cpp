#include <iostream>
#include <string>

class ArrayIntException
{
    std::string error;
public:
    ArrayIntException(std::string err): error{ err }{
    }

    std::string getError() const { return error; }
};

class ArrayInt
{
    int arr[3]{}; // для простоты предполагаем, что массив имеет длину 3
public:
    ArrayInt() {}

    int getLength() const { return 3; }

    int& operator[](const int index)
    {
        if (index < 0 || index >= getLength())
            throw ArrayIntException{ "Invalid index" };

        return arr[index];
    }

};

int main()
{
    ArrayInt ob;

    try
    {
        ob[5] = 123;
    }
    catch (const ArrayIntException& excp)
    {
        std::cerr << "Exception detected (" << excp.getError() << ")\n";
    }
}
