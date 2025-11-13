#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
    int value;
    BinarySearchTree *left_child;
    BinarySearchTree *right_child;

    BinarySearchTree(int val)
    {
        value = val;
        left_child = nullptr;
        right_child = nullptr;
    }

    void insert_node(int val)
    {
        if (val <= value)
        {
            if (left_child != nullptr)
                left_child->insert_node(val);
            else
                left_child = new BinarySearchTree(val);
        }
        else
        {
            if (right_child != nullptr)
                right_child->insert_node(val);
            else
                right_child = new BinarySearchTree(val);
        }
    }

    // --- Find minimum value in subtree ---
    int find_minimum_value()
    {
        if (left_child != nullptr)
            return left_child->find_minimum_value();
        else
            return value;
    }

    // --- Clear node data ---
    void clear_node()
    {
        value = -1; // use -1 as placeholder for "cleared" (since int can’t be nullptr)
        left_child = nullptr;
        right_child = nullptr;
    }

    // --- Remove a node ---
    bool remove_node(int val, BinarySearchTree *parent = nullptr)
    {
        if (val < value && left_child != nullptr)
            return left_child->remove_node(val, this);
        else if (val < value)
            return false;
        else if (val > value && right_child != nullptr)
            return right_child->remove_node(val, this);
        else if (val > value)
            return false;
        else
        {
            // Case 1: No children (leaf node)
            if (left_child == nullptr && right_child == nullptr && parent != nullptr)
            {
                if (parent->left_child == this)
                    parent->left_child = nullptr;
                else if (parent->right_child == this)
                    parent->right_child = nullptr;
                clear_node();
            }
            // Case 2: One left child
            else if (left_child != nullptr && right_child == nullptr && parent != nullptr)
            {
                if (parent->left_child == this)
                    parent->left_child = left_child;
                else if (parent->right_child == this)
                    parent->right_child = left_child;
                clear_node();
            }
            // Case 3: One right child
            else if (right_child != nullptr && left_child == nullptr && parent != nullptr)
            {
                if (parent->left_child == this)
                    parent->left_child = right_child;
                else if (parent->right_child == this)
                    parent->right_child = right_child;
                clear_node();
            }
            // Case 4: Two children
            else
            {
                value = right_child->find_minimum_value();
                right_child->remove_node(value, this);
            }
            return true;
        }
    }

    // --- Inorder traversal (sorted output) ---
    void inorder_traversal()
    {
        if (left_child != nullptr)
            left_child->inorder_traversal();
        if (value != -1)
            cout << value << " ";
        if (right_child != nullptr)
            right_child->inorder_traversal();
    }
};

int main()
{
    BinarySearchTree *root = new BinarySearchTree(50);
    root->insert_node(76);
    root->insert_node(21);
    root->insert_node(4);
    root->insert_node(32);
    root->insert_node(100);
    root->insert_node(64);
    root->insert_node(52);

    cout << "Inorder before deletion: ";
    root->inorder_traversal();
    cout << endl;

    root->remove_node(76); // delete node 76

    cout << "Inorder after deletion: ";
    root->inorder_traversal();
    cout << endl;
    delete (root);
    return 0;
}
