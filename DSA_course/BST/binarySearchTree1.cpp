#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
    int value;
    BinarySearchTree *left_child;
    BinarySearchTree *right_child;

    // Constructor
    BinarySearchTree(int val)
    {
        value = val;
        left_child = nullptr;
        right_child = nullptr;
    }

    // Insert function
    void insert_node(int val)
    {
        if (val <= value)
        {
            if (left_child != nullptr)
            {
                left_child->insert_node(val);
            }
            else
            {
                left_child = new BinarySearchTree(val);
            }
        }
        else
        { // val > value
            if (right_child != nullptr)
            {
                right_child->insert_node(val);
            }
            else
            {
                right_child = new BinarySearchTree(val);
            }
        }
    }
    // Inorder traversal (Left -> Root -> Right)
    void inorder_traversal()
    {
        if (left_child != nullptr)
            left_child->inorder_traversal();
        cout << value << " ";
        if (right_child != nullptr)
            right_child->inorder_traversal();
    }
};

int main()
{
    // Example usage
    BinarySearchTree *root = new BinarySearchTree(10);
    root->insert_node(76);
    root->insert_node(21);
    root->insert_node(4);
    root->insert_node(32);
    root->insert_node(100);
    root->insert_node(64);
    root->insert_node(52);

    cout << "Inorder traversal (sorted order): ";
    root->inorder_traversal();
    cout << endl;
    return 0;
}
