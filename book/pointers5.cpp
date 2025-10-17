#include <iostream>

using namespace std;

// int &f2(int a[], int i)
// {
//     return a[i];
// }
int *f2(int a[], int i)
{
    return &a[i];
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << a[3] << endl;
    // *f2(a, 3) = 6;
    // cout << a[3] << endl;
    // cout << *f2(a, 3) << endl;
    return 0;
}