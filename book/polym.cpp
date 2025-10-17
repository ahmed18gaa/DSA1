#include <iostream>
using namespace std;
class Class1
{
public:
    virtual void f()
    {
        cout << "Function f() in Class1\n";
    }
    void g()
    {
        cout << "Function g() in Class1\n";
    }
};
class Class2
{
public:
    virtual void f()
    {
        cout << "Function f() in Class2\n";
    }
    void g()
    {
        cout << "Function g() in Class2\n";
    }
};
class Class3
{
public:
    virtual void h()
    {
        cout << "Function h() in Class3\n";
    }
};
int main()
{
    Class1 ob1, *p;
    Class2 ob2;
    Class3 ob3;
    p = &ob1;
    p->f();
    p->g();
    p = (Class1 *)&ob2;
    p->f();
    p->g();
    p = (Class1 *)&ob3;
    p->f();
    p->g();
    // p->h();

    return 0;
}