#include <iostream>

using namespace std;
int main()
{
    int n = 5, *p = &n, &r = n;
    cout << r << " " << *p << " " << r << endl;
    n = 7;
    cout << r << " " << *p << " " << r << endl;
    *p = 9;
    cout << r << " " << *p << " " << r << endl;
    r = 10;
    cout << r << " " << *p << " " << r << endl;
    return 0;
}