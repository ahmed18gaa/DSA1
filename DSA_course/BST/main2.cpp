#include <iostream>
#include <string>

using namespace std;

class BinaryTree
{
public:
    string value;
    BinaryTree *left_child;
    BinaryTree *right_child;

    // Constructor
    BinaryTree(const string &val)
    {
        value = val;
        left_child = nullptr;
        right_child = nullptr;
    }

    // insert_left method
    void insert_left(const string &val)
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
    void insert_right(const string &val)
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
    BinaryTree *a_node = new BinaryTree("a");
    a_node->insert_left("b");
    a_node->insert_right("c");

    BinaryTree *b_node = a_node->left_child;
    b_node->insert_right("d");

    BinaryTree *c_node = a_node->right_child;
    c_node->insert_left("e");
    c_node->insert_right("f");

    BinaryTree *d_node = b_node->right_child;
    BinaryTree *e_node = c_node->left_child;
    BinaryTree *f_node = c_node->right_child;

    // cout << a_node->value << endl; // a
    // cout << b_node->value << endl; // b
    // cout << c_node->value << endl; // c
    // cout << d_node->value << endl; // d
    // cout << e_node->value << endl; // e
    // cout << f_node->value << endl; // f

    cout << "Pre-order traversal:" << endl;
    a_node->pre_order(); // a, b, d, c, e, f

    cout << "\nIn-order traversal:" << endl;
    a_node->in_order(); // b, d, a, e, c, f

    cout << "\nPost-order traversal:" << endl;
    a_node->post_order(); // d, b, e, f, c, a
    cout << endl;

    delete f_node;
    delete e_node;
    delete d_node;
    delete c_node;
    delete b_node;
    delete a_node;

    return 0;
}
