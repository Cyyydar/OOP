#ifndef DINMAS_H
#define DINMAS_H


class DinMas
{
    int RazMas = 0;
    int *Mas = nullptr;

public:
    DinMas(const DinMas &ob);
    DinMas&operator=(const DinMas &ob);
    DinMas(DinMas&&ob);
    DinMas&operator=(DinMas &&ob);
    DinMas(int k, int m);
    DinMas();
    ~DinMas();

    void Create ();
    void Show() const;

};

#endif // DINMAS_H
