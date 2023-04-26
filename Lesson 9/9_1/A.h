#ifndef A_H
#define A_H
class B;

class A
{
    float x;

public:
    void set_x(float g);
    float get_x();
    friend void show(A ob1, B ob2);
};

#endif // A_H
