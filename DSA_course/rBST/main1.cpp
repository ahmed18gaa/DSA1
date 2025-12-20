#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    bool rContains(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return false;
        if (currentNode->value == value)
            return true;
        if (value < currentNode->value)
        {
            return rContains(currentNode->left, value);
        }
        else
        {
            return rContains(currentNode->right, value);
        }
    }

    bool rContains(int value)
    {
        return rContains(root, value);
    }

    Node *rInsert(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return new Node(value);
        if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }

    void rInsert(int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
        }
        rInsert(root, value);
    }

    void destroy(Node *currentNode)
    {
        if (currentNode == nullptr)
            return;
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    Node *getRoot()
    {
        return root;
    }

    ~BinarySearchTree() { destroy(root); }
};

int main()
{
    BinarySearchTree *myBST = new BinarySearchTree();
    myBST->rInsert(47);
    myBST->rInsert(21);
    myBST->rInsert(76);
    myBST->rInsert(18);
    myBST->rInsert(52);
    myBST->rInsert(82);
    myBST->rInsert(27);

    cout << "\nBST Contains 27:\n";
    cout << myBST->rContains(27);
    cout << "\nBST Contains 17:\n";
    cout << myBST->rContains(17);

    myBST->rInsert(5);
    cout << "\nBST Contains 5:\n";
    cout << myBST->rContains(5);

    cout << endl;
    delete myBST;
    return 0;
}