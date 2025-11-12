#include <iostream>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left_child;
    BinaryTree *right_child;

    // Constructor
    BinaryTree(int val)
    {
        value = val;
        left_child = nullptr;
        right_child = nullptr;
    }

    // insert_left method
    void insert_left(int val)
    {
        if (left_child == nullptr)
        {
            left_child = new BinaryTree(val);
        }
        else
        {
            BinaryTree *new_node = new BinaryTree(val);
            new_node->left_child = left_child;
            left_child = new_node;
        }
    }

    // insert_right method
    void insert_right(int val)
    {
        if (right_child == nullptr)
        {
            right_child = new BinaryTree(val);
        }
        else
        {
            BinaryTree *new_node = new BinaryTree(val);
            new_node->right_child = right_child;
            right_child = new_node;
        }
    }

    // pre_order traversal
    void pre_order()
    {
        cout << value << " ";

        if (left_child != nullptr)
            left_child->pre_order();

        if (right_child != nullptr)
            right_child->pre_order();
    }

    // in_order traversal
    void in_order()
    {
        if (left_child != nullptr)
            left_child->in_order();

        cout << value << " ";

        if (right_child != nullptr)
            right_child->in_order();
    }

    // post_order traversal
    void post_order()
    {
        if (left_child != nullptr)
            left_child->post_order();

        if (right_child != nullptr)
            right_child->post_order();

        cout << value << " ";
    }
};

int main()
{
    BinaryTree *a_node = new BinaryTree(1);
    a_node->insert_left(2);
    a_node->insert_right(3);

    BinaryTree *b_node = a_node->left_child;
    b_node->insert_right(4);

    BinaryTree *c_node = a_node->right_child;
    c_node->insert_left(5);
    c_node->insert_right(6);

    cout << "Pre-order traversal: \n";
    a_node->pre_order(); // 1 2 4 3 5 6
    cout << endl;

    cout << "In-order traversal: \n";
    a_node->in_order(); // 2 4 1 5 3 6
    cout << endl;

    cout << "Post-order traversal: \n";
    a_node->post_order(); // 4 2 5 6 3 1
    cout << endl;

    // Free memory (optional cleanup)
    delete a_node->right_child->right_child; // 6
    delete a_node->right_child->left_child;  // 5
    delete a_node->right_child;              // 3
    delete a_node->left_child->right_child;  // 4
    delete a_node->left_child;               // 2
    delete a_node;                           // 1

    return 0;
}
