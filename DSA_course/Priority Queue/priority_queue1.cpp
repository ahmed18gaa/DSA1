#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // priority_queue<int> pq;
    // pq.push(1);
    // pq.push(0);
    // pq.push(2);
    // pq.push(3);
    // pq.push(4);
    // pq.push(5);
    // pq.push(6);
    // while (!pq.empty())
    // {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }
    // priority_queue<int, vector<int>, greater<int>> pq;
    // pq.push(6);
    // pq.push(5);
    // pq.push(4);
    // pq.push(3);
    // pq.push(2);
    // pq.push(1);
    // pq.push(0);
    // while (!pq.empty())
    // {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }

    // Pseudo Traversal
    /*
    priority_queue<int> pq;
    pq.push(9);
    pq.push(8);
    pq.push(6);

    priority_queue<int> temp(pq);

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    */
    // Changing Priority Queue Order
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(9);
    pq.push(8);
    pq.push(6);

    auto temp = pq;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    return 0;
}
