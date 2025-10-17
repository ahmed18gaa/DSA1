#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Create a list of integers
    list<int> myList;

    // Add elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    // Display elements
    cout << "List elements: ";
    for (int n : myList)
    {
        cout << n << " ";
    }
    cout << endl;
    /*
    list<int> l = {3, 2};

    // Inserting an element at the end
    l.push_back(5);

    // Inserting an element at the beginning
    l.push_front(1);

    // Inserting an element at a specific position
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 4);

    for (auto i : l)
        cout << i << " ";
    cout << endl;
    */
    /*
    list<int> l = {1, 3, 4, 2, 5};

    // Accessing first and last elements
    cout << l.front() << endl;
    cout << l.back() << endl;

    // Access third element
    cout << *next(l.begin(), 2) << endl;
    */
    /*
    list<int> l = {1, 3, 4, 2, 5};

    // Changing the first element
    l.front() = 11;

    // Move iterator to the second element
    auto it = l.begin();
    advance(it, 2);

    // Update the value using iterator
    *it = 10;

    for (auto i : l)
        cout << i << " ";
    cout << endl;
    */
    /*
    list<int> l = {1, 3, 4, 2, 5};

    // Finding 4
    auto it = find(l.begin(), l.end(), 4);

    if (it != l.end())
        cout << *it;
    else
        cout << "Element Not Found!";
    cout << endl;
    */
    /*
    list<int> l = {1, 3, 4, 2, 5};
    // Traversing using iterators
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
    */
    /*list<int> l = {10, 15, 15, 20, 20, 10};
    l.sort();
    l.unique();
    // l.reverse();

    for (int x : l)
    {
        cout << x << " ";
    }
    cout << endl;
*/
    return 0;
}