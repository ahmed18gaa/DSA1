#include <iostream>
#include <queue>
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
private:
    Node *root = nullptr;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value)
    {
        Node *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    void BFS()
    {
        if (root == nullptr)
            return;
        queue<Node *> myQueue;
        myQueue.push(root);
        while (!myQueue.empty())
        {
            Node *currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";
            if (currentNode->left)
                myQueue.push(currentNode->left);
            if (currentNode->right)
                myQueue.push(currentNode->right);
        }
        cout << endl;
    }

    void DFSPreOrder(Node *currentNode)
    {
        cout << currentNode->value << " ";
        if (currentNode->left)
        {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right)
        {
            DFSPreOrder(currentNode->right);
        }
    }
    void DFSPreOrder()
    {
        DFSPreOrder(root);
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
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);
    cout << "BFS: ";
    myBST->BFS();
    cout << "DFS Pre Order: ";
    myBST->DFSPreOrder();
    cout << endl;

    delete (myBST);
    return 0;
}