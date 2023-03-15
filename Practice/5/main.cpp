#include <iostream>

using namespace std;

class DinMassiv{
    double**Mas;
    int line, column;
public:
    DinMassiv(int N, int M, double x, double y);
    ~DinMassiv(){
        cout << "\n Destructor \n";
        for(int i = 0; i < line; i++){
            delete[]Mas[i];
        }

        delete[]Mas;
    }
    DinMassiv(const DinMassiv &ob);
    DinMassiv& operator= (const DinMassiv &ob);

    void createMas();
    void showMas() const;
};

int main()
{
    cout << "ob1\n";
    DinMassiv ob1(2, 2, 4.5, 7.3);
    ob1.showMas();
    ob1.createMas();
    ob1.showMas();

    cout << "ob2\n";
    DinMassiv ob2(0,0,0,0);
    ob2.showMas();
    ob2.createMas();
    ob2.showMas();

    cout << "ob3\n";
    DinMassiv ob3(ob1);
    ob3.showMas();

    cout << "ob4\n";
    DinMassiv ob4 = ob2;
    ob4.showMas();
    ob4 = ob3 = ob2;
    ob4 = ob4;
    ob4.showMas();

    cout << "ob1\n";
    ob1.showMas();
    cout << "ob2\n";
    ob2.showMas();
    cout << "ob3\n";
    ob3.showMas();
    cout << "ob4\n";
    ob4.showMas();
    return 0;
}

DinMassiv::DinMassiv(int N, int M, double x, double y){
    cout << "Costructor start working\n\n";
    if(N <= 0 || M<= 0){
        cout << "Error: bad array size\n";
        Mas = nullptr;
        line = 0;
        column = 0;
        return;
    }
    line = N;
    column = M;
    Mas = new double*[line];
    for(int i = 0; i < line; i++){
        Mas[i] = new double[column];
    }
    for(int i = 0; i < line; i++)
        for(int j = 0; j < column; j++)
            Mas[i][j] = (x-j)*(x+i)+y*y;
}

DinMassiv::DinMassiv(const DinMassiv &ob){
    cout << " Constructor of copy";
    if(this == &ob) {
        this->Mas = nullptr;
        this->line = 0;
        this->column = 0;
        return;
    }
    if(ob.Mas == nullptr){
        this->Mas = nullptr;
        this->line = 0;
        this->column = 0;
        return;
    }
    this->line = ob.line;
    this->column = ob.column;
    this->Mas = new double*[this->line];
    for(int i = 0; i < this->line; i++){
        this->Mas[i] = new double[this->column];
        for(int j = 0; j < this->column; j++){
            this->Mas[i][j] = ob.Mas[i][j];
        }
    }
}

DinMassiv& DinMassiv::operator=(const DinMassiv &ob){
    cout << " Apropriation\n\n";
    if(this == &ob){
        cout << "Self copy error\n";
        return *this;
    }
    for(int i = 0; i < this->line; i++)
        delete[]this->Mas[i];
    delete[]this->Mas;

    if(ob.Mas == nullptr){
        this->Mas = nullptr;
        this->line = 0;
        this->column = 0;
        return *this;
    }
    this->line = ob.line;
    this->column = ob.column;
    this->Mas = new double*[this->line];
    for(int i = 0; i < this->line; i++){
        this->Mas[i] = new double[this->column];
        for(int j = 0; j < this->column; j++){
            this->Mas[i][j] = ob.Mas[i][j];
        }
    }
    return *this;
}

void DinMassiv::createMas(){
    if(Mas != nullptr) {
        cout << "Array already created\n";
        for(int i = 0; i < line; i++){
            for(int j = 0; j < column; j++){
                cout << " " << Mas[i][j];
            }
            cout << endl;
        }
        cout << "\nEnter 1 if need recreate array ";
        cout << "Or 0\n";
        int f;
        cin >> f;
        if(f == 0)
            return;
    }
    cout << "Enter count of lines:\n";
    cout << "(positive integer number)";
    cin >> line;
    cout << "Enter count of columns:\n";
    cout << "(positive integer number)";
    cin >> column;
    delete[]Mas;
    Mas = new double*[line];
    for(int i = 0; i < line; i++)
        Mas[i] = new double[column];
    cout << "Enter real numbers:\n";
    for(int i = 0; i < line; i++){
        for(int j = 0; j < column; j++){
            cout << " Mas [" << i << "][" << j << "] = ";
            cin >> Mas[i][j];
        }
    }
    cout << "Entry complited\n";
}

void DinMassiv::showMas() const {
    if(Mas == nullptr){
        cout << " Array is not created\n\n";
        return;
    }
    cout << " Array:\n";
    for(int i = 0; i < line; i++){
        for(int j = 0; j < column; j++){
            cout << " " << Mas[i][j];
        }
        cout << endl;
    }
}
