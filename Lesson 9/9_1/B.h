#ifndef B_H
#define B_H

class A;

class B
{
    float y;
public:
    void set_y(float g);
    float get_y();
    friend void show(A ob1, B ob2);

};

#endif // B_H
