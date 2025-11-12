#include <iostream>
#include <queue>

using namespace std;

class BinaryTree
{
public:
    int value;
    BinaryTree *left_child;
    BinaryTree *right_child;

    BinaryTree(int val)
    {
        value = val;
        left_child = nullptr;
        right_child = nullptr;
    }

    // Traversals
    void pre_order()
    {
        cout << value << " ";
        if (left_child)
            left_child->pre_order();
        if (right_child)
            right_child->pre_order();
    }

    void in_order()
    {
        if (left_child)
            left_child->in_order();
        cout << value << " ";
        if (right_child)
            right_child->in_order();
    }

    void post_order()
    {
        if (left_child)
            left_child->post_order();
        if (right_child)
            right_child->post_order();
        cout << value << " ";
    }

    void bfs()
    {
        queue<BinaryTree *> q;
        q.push(this);
        while (!q.empty())
        {
            BinaryTree *current = q.front();
            q.pop();
            cout << current->value << " ";
            if (current->left_child)
                q.push(current->left_child);
            if (current->right_child)
                q.push(current->right_child);
        }
    }
};

int main()
{
    // Build the tree shown in the image
    BinaryTree *root = new BinaryTree(1);
    root->left_child = new BinaryTree(2);
    root->right_child = new BinaryTree(5);
    root->left_child->left_child = new BinaryTree(3);
    root->left_child->right_child = new BinaryTree(4);
    root->right_child->left_child = new BinaryTree(6);
    root->right_child->right_child = new BinaryTree(7);

    cout << "BFS (level-order): \n";
    root->bfs(); // 1 2 5 3 4 6 7
    cout << "\nPre-order: \n";
    root->pre_order(); // 1 2 3 4 5 6 7
    cout << "\nIn-order: \n";
    root->in_order(); // 3 2 4 1 6 5 7
    cout << "\nPost-order: \n";
    root->post_order(); // 3 4 2 6 7 5 1
    cout << endl;

    // Cleanup (manual delete)
    delete root->right_child->right_child; // 7
    delete root->right_child->left_child;  // 6
    delete root->right_child;              // 5
    delete root->left_child->right_child;  // 4
    delete root->left_child->left_child;   // 3
    delete root->left_child;               // 2
    delete root;                           // 1

    return 0;
}
