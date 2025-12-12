
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void printHeap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    const vector<int> &getHeap() const
    {
        return heap;
    }
    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] < heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }
    void sinkDown(int index)
    {
        int minIndex = index;
        while (true)
        {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex])
            {
                minIndex = leftIndex;
            }

            if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex])
            {
                minIndex = rightIndex;
            }

            if (minIndex != index)
            {
                swap(index, minIndex);
                index = minIndex;
            }
            else
            {
                return;
            }
        }
    }
    int remove()
    {
        if (heap.empty())
        {
            return INT_MIN;
        }

        int minValue = heap.front();

        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return minValue;
    }
};

int main()
{
    MinHeap *myHeap = new MinHeap();
    myHeap->insert(95);
    myHeap->insert(75);
    myHeap->insert(80);
    myHeap->insert(55);
    myHeap->insert(60);
    myHeap->insert(50);
    myHeap->insert(65);
    myHeap->printHeap();
    myHeap->remove();
    myHeap->printHeap();
    myHeap->remove();
    myHeap->printHeap();
    delete myHeap;
    return 0;
}