#include <iostream>
#include <string.h>
using namespace std;

class BaseClass
{
public:
    BaseClass() {}
    void f(string s = "unknown")
    {
        cout << "Function f() in BaseClass called from " << s << endl;
    }

protected:
    void g(string s = "unknown")
    {
        cout << "Function g() in BaseClass called from " << s << endl;
    }

private:
    void h(string s = "unknown")
    {
        cout << "Function h() in BaseClass" << endl;
    }
};

class Derived1Level1 : public virtual BaseClass
{
public:
    void f(string s = "unknown")
    {
        cout << "Function f() in Derived1Level1 called from " << s << endl;
        g("Derived1Level1");
        // h("Derived1Level1");
    }
    void h(string s = "unknown")
    {
        cout << "Function h() in Derived1Level1 called from " << s << endl;
    }
};

class Derived2Level1 : public virtual BaseClass
{
    void f(string s = "unknown")
    {
        cout << "Function f() in Derived2Level1 called from " << s << endl;
        g("Derived2Level1");
        // h("Derived1Level1");
    }
};

class DerivedLevel2 : public Derived1Level1, public Derived2Level1
{
public:
    void f(string s = "unknown")
    {
        cout << "Function f() in DerivedLevel2 called from " << s << endl;
        g("DerivedLevel2");
        Derived1Level1::h("DerivedLevel2");
        BaseClass::f("DerivedLevel2");
    }
};

int main()
{
    BaseClass bc;
    Derived1Level1 d1l1;
    Derived2Level1 d2l1;
    DerivedLevel2 dl2;
    bc.f("main(1)");
    // bc.g();
    // bc.h();
    d1l1.f("main(2)");
    // d1l1.g();
    d1l1.h("main(3)");
    d1l1.f("main(4)");
    // d2l1.g();
    // d2l1.h();
    dl2.f("main(5)");
    // dl2.g();
    dl2.h();

    return 0;
}