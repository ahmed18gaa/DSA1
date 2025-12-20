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
private:
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

    int minValue(Node *currentNode)
    {
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }

    Node *deleteNode(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return nullptr;
        if (value < currentNode->value)
        {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else
        {
            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                delete (currentNode);
                return nullptr;
            }
            else if (currentNode->left == nullptr)
            {
                Node *temp = currentNode->right;
                delete (currentNode);
                return temp;
            }
            else if (currentNode->right == nullptr)
            {
                Node *temp = currentNode->left;
                delete (currentNode);
                return temp;
            }
            else
            {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }
        return currentNode;
    }

    void deleteNode(int value)
    {
        root = deleteNode(root, value);
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
    myBST->rInsert(27);
    myBST->rInsert(52);
    myBST->rInsert(82);

    delete myBST;
    return 0;
}