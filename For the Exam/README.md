# Небольшая шпаргалка к экзамену по ООП
---
<a name="Содержание"></a> 
1. [Классы и уровень доступа](#1)
2. [Конструкторы и деструкторы](#2)
3. [Наследование](#3)
4. [Наследование конструктора и деструктора](#4)
5. [Конструктор копирования и перегрузка оператора "присвоение"](#5)
6. [lvalue и rvalue](#6)
7. [Конструктор перемещения и перегрузка оператора "присвоение"](#7)
8. [Безопасный ввод](#8)
9. [Работа с файлами](#9)
---
- ### [↑](#Содержание) Классы и уровень доступа <a name="1"></a> 

```c++
class human{
    string name;
    int age;
    void sayMyName{
        std::cout << "Walter White \n";
    }
};
```
Ключевые слова, которые ставятся перед списком членов класса и дают разный уровень доступа
- __public__ - к членам класса можно обратиться из любой функции
- __privite__ - к членам класса можно обратиться только из самого класса или дружественных функций
- __protected__ - к членам класса можно обратиться из самого класса, дружественных функций и из дочерних классов с уровнем доступа __public__ или __protected__
```c++
class human{
    string name;
    int age;
public:
    void sayMyName(){
        std::cout << "Walter White \n";
    }
};
```
- ### [↑](#Содержание) Конструкторы и деструкторы <a name="2"></a> 
Конструкторы - функции, которые вызываются при создании экземпляра класса
Деструкторы - функция, которая вызывается при выходе экземпляра класса из области видимости
```cpp
class human{
    string name;
    int age;
public:
    human(){ // Конструктор 
        name = "Volodya";
        age = 99;
    }
    human(string n, int a){ // Конструктор с параметрами
        name = n;
        age = a;
    }
    ~human(){ // Деструктор
        name = "";
        age = 0;
    }
};
```
- ### [↑](#Содержание) Наследование <a name="3"></a> 
    - __public__ - публичные (public) и защищенные (protected) члены наследуются без изменения уровня доступа к ним;
    - __protected__ — все унаследованные члены становятся защищенными;
    - __private__ — все унаследованные члены становятся приватными.
```c++
class A
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};
class B : public A {
    // x  public
    // y protected  (недоступен снаружи, но доступен внутри класса и у классов-наследников)
    // z недоступен из B
};
class C : protected A {
    // x protected 
    // y protected
    // z недоступен из C
};
class D : private A {
    // x private
    // y private
    // z недоступен из D
};
```
- ### [↑](#Содержание) Наследование конструктора и деструктора <a name="4"></a> 
```c++
class human{
    string name;
    int age;
public:
    human(){ // Конструктор
        name = "Volodya";
        age = 99;
    }
    human(string n, int a){ // Конструктор с параметрами
        name = n;
        age = a;
    }
    ~human(){ // Деструктор
        name = "";
        age = 0;
    }
};

class student: public human{
    int course;
public:
    student(){ // Конструктор
        course = 1;
        // конструктор без параметров будет унаследован автоматически
    }
    student(string n, int a, int c): human(n, a);{ // Конструктор с параметрами необходимо унаследовать в ручную
    // и пробросить нужные параметры
    // а нужные параметры забрать себе
        course = c;
    }
    ~student(){ // Деструктор также унаследуется автоматически, требуется прописать только деструктор класса наследника
        course = -1;
    }
};
```

- ### [↑](#Содержание) Конструктор копирования и перегрузка оператора "присвоение" <a name="5"></a> 
```c++
DinMas(const DinMas &ob) { // если при создании экземпляра в скобках указать другой экземпляр, то он скопирует его данные
    if((ob.Mas != nullptr) && (ob.RazMas != 0)){
        RazMas = ob.RazMas;
        Mas = new int[RazMas];
        for(int i = 0; i < RazMas; i++){
            Mas[i] = ob.Mas[i];
        }
        cout << "\n Copy constructor";
    }
}
```
Перегрузка оператора "присвоение":
```c++
DinMas& DinMas::operator=(const DinMas &ob){
    if(this == &ob){
        cout << "\n Self copy error\n";
        return *this;
    }
    delete[]Mas;
    Mas = nullptr;
    RazMas = 0;

    if((ob.Mas != nullptr) && (ob.RazMas != 0)){
        Mas = new int[ob.RazMas];
        RazMas = ob.RazMas;
        for(int i = 0; i < this -> RazMas; i++){
            this->Mas[i] = ob.Mas[i];
        }
    }
    cout << "\n Appropriation \n";
    return *this;
}
```
работает при вызове через равно
```c++
    ob1 = ob2
```
- ### [↑](#Содержание) lvalue и rvalue <a name="6"></a> 
__lvalue__ - то, у чего есть имя и адрес в памяти
__rvalue__ - то, у чего есть только адрес и с ним можно делать что душе угодно
Оператор __move()__ помечает переменную как __rvalue__, явно дав понять компилятору, что с этим адресом можно делать что угодно
 __rvalue__ обозначается двумя символами __&__
```cpp
class vector2d{
public:
    int* v = new int[2];
    vector2d(int X, int Y){
        v[0] = X;
        v[1] = Y;
    }
    vector2d& operator=(vector2d &other){
        v[0] = other.v[0];
        v[1] = other.v[1];
        return *this;
    }


    void print(){
        cout << v[0] << " " << v[1] << " - "<<&v[0] << " " << &v[1] <<endl;
    }
};

vector2d getNorm(){ // функция, возвращающая нормальный вектор
    return vector2d(1,1);
}

int main()
{
    // Создадим два вектора
    vector2d g(1,2); 
    vector2d a(3,4);
    g.print();
    a.print();
    g = a;
    // Присвоить один вектор другому мы можем, ведь у нас написана перегрузка "="
    g.print();
    a.print();
    g = getNorm(); // но эта строчка вызовет ошибку
    // Дело в том, что функция возвращает вектор, у которого нет имени
    // А как мы помним, у чего нет имени - rvalue
    g.print();
    return 0;
}
```
Чтобы программа заработала необходимо написать перегрузку оператора "присвоение" с входными параметрами __rvalue__ , но делать присвоение копированием бессмысленно, ведь через строчку этот адрес уйдет из области видимости, ведь у него нет имени. Лучше написать присвоение через перемещение и просто передать управление этой памятью. Но необходимо помнить, что нужно правильно освободить память, чтобы избежать утечек.

```cpp
vector2d& operator=(vector2d &&other){ // && обозначает, что мы работает с rvalue
    if(this == &other) // проверяем на самокопирование
        return *this;
    delete[]v; // освобождаем старую память
    v = other.v; // берем управление новой памятью
    other.v = nullptr; // необходимо использовать, чтобы старый массив не имел доступа к новому (в примере с натуральным rvalue это бесполезно)
    return *this;
}
```
Чтобы инициализировать перемещение нужно сделать другую переменную __rvalue__
```cpp
    g = move(a);
```
__move()__ делает из переменной "a" rvalue и вызывается перегрузка с перемещением

- ### [↑](#Содержание) Конструктор перемещения и перегрузка оператора "присвоение" <a name="7"></a> 
Конструктор перемещение
```cpp
    DinMas(DinMas&&ob): Mas{nullptr}, RazMas{0} {
        if((ob.Mas != nullptr) && (ob.RazMas != 0)){
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr;
            ob.RazMas = 0;
        }
    }
```
Перегрузка оператора "присвоение" через перемещение
```cpp
    DinMas&operator=(DinMas &&ob){
        if(this == &ob)
            return *this;
        delete[]Mas;
        Mas = nullptr;
        RazMas = 0;
        if((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr;
            ob.RazMas = 0;
        }
        return *this;
    }
```

- ### [↑](#Содержание) Безопасный ввод <a name="8"></a> 
```cpp
 #include <limits>
 
 ...
 
 double getDouble() {
 	double x;
 	while(true) {
 
 	cin >> x; // пытаемся ввести данные

 	if(cin.fail()) { // если если ошибка ввода, то сообщаем об этом
 		cin.clear();
 		cin.ignore(numeric_limits<streamsize>::max(), '\n');
 		cout << "Error, try again\n";
 		continue; // и пробуем еще раз
 	}
 	if(cin.peek()!='\n') { // если в буфере осталось что-то, выдаем ошибку
 		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера
 		cout << "Error, try again\n";
 		continue;
 	}
 	cin.ignore(numeric_limits<streamsize>::max(), '\n');

 	return x; // возвращаем число
 }
 ```
 
 
- ### [↑](#Содержание) Работа с файлами <a name="9"></a> 
Запись в файл
```cpp
#include <fstream>
...
main(){
    ofstream fout {"text.txt"};
    for(int i = 0; i < 10; i++){
        fout << i << " ";
    }
    return 0
}
```
Чтение из файла
```cpp
#include <fstream>
...
main(){
    ifstream fin {"text.txt"};
    for(int i = 0; i < 10; i++){
        fin >> a;
        cout << a << " ";
    }
    return 0
}
```
Удаление файла 
```cpp
#include <ctdio>
...
main(){
    string address = "text.txt";
    if (remove(address.c_str()) != 0){ // c_str() преобразует строку в чары.
        // возвращает 0, если файл удален
        cerr << "File was not removed";
    }
}
```
