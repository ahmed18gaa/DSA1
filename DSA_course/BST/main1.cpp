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

    void DFSPostOrder(Node *currentNode)
    {
        if (currentNode->left)
        {
            DFSPostOrder(currentNode->left);
        }
        if (currentNode->right)
        {
            DFSPostOrder(currentNode->right);
        }
        cout << currentNode->value << " ";
    }
    void DFSPostOrder()
    {
        DFSPostOrder(root);
    }

    void DFSInOrder(Node *currentNode)
    {
        if (currentNode->left)
        {
            DFSInOrder(currentNode->left);
        }
        cout << currentNode->value << " ";
        if (currentNode->right)
        {
            DFSInOrder(currentNode->right);
        }
    }
    void DFSInOrder()
    {
        DFSInOrder(root);
    }

    int maxDepth(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    void maxDepth()
    {
        cout << "Max Depth: " << maxDepth(root) << endl;
    }

    bool isCompleteTree(Node *root)
    {
        if (root == nullptr)
            return true;
        queue<Node *> q{{root}};
        while (q.front() != nullptr)
        {
            Node *node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        while (!q.empty() && q.front() == nullptr)
            q.pop();
        return q.empty();
    }
    void isCompleteTree()
    {
        cout << boolalpha;
        cout << "Is Complete Tree: " << isCompleteTree(root) << endl;
    }

    vector<vector<int>> zigzagLevelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        deque<Node *> dq;
        dq.push_back(root);
        bool reverse = false;

        while (!dq.empty())
        {
            int size = dq.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                if (!reverse)
                {
                    Node *node = dq.front();
                    dq.pop_front();
                    level.push_back(node->value);
                    if (node->left)
                        dq.push_back(node->left);
                    if (node->right)
                        dq.push_back(node->right);
                }
                else
                {
                    Node *node = dq.back();
                    dq.pop_back();
                    level.push_back(node->value);
                    if (node->right)
                        dq.push_front(node->right);
                    if (node->left)
                        dq.push_front(node->left);
                }
            }

            res.push_back(level);
            reverse = !reverse;
        }

        return res;
    }
    void zigzagLevelOrder()
    {
        cout << "Zigzag Level Order:\n";
        vector<vector<int>> result = zigzagLevelOrder(root);
        for (const auto &level : result)
        {
            for (int val : level)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    int sumOfLeftLeaves(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int sum = 0;
        if (root->left && root->left->left == NULL && root->left->right == NULL)
        {
            sum = sum + (root->left->value);
        }
        else
        {
            sum = sum + sumOfLeftLeaves(root->left);
        }
        sum = sum + sumOfLeftLeaves(root->right); // process right subtree

        return sum;
    }
    void sumOfLeftLeaves()
    {
        cout << "Sum Of Left Leaves: " << sumOfLeftLeaves(root) << endl;
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
    cout << endl;

    cout << "DFS Pre Order: ";
    myBST->DFSPreOrder();
    cout << endl;

    cout << "DFS Post Order: ";
    myBST->DFSPostOrder();
    cout << endl;

    cout << "DFS In Order: ";
    myBST->DFSInOrder();
    cout << endl;

    myBST->maxDepth();

    myBST->isCompleteTree();

    myBST->zigzagLevelOrder();

    myBST->sumOfLeftLeaves();

    delete (myBST);
    return 0;
}