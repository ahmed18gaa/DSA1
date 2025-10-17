#include <iostream>

using namespace std;

int main()
{
    int i = 10, j, *p, *q;
    p = 0;
    q = 0;
    p = &i;
    cout << i << endl;
    *p = 20;
    cout << i << endl;
    j = 2 * *p;
    cout << j << endl;
    q = &i;
    *p = *q - 1;
    cout << i << endl;
    q = &j;
    *p = *q - 1;
    cout << i << endl;

    cout << &i << endl;
    cout << &j << endl;
    cout << p << endl;

    delete p;
    delete q;
    return 0;
}