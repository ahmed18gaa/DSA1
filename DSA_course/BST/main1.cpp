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
    int res = 0;

    int dfs(Node *root)
    {
        if (!root)
        {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        res = max(res, left + right);

        return 1 + max(left, right);
    }

    void dfs(Node *node, int row, int col, vector<tuple<int, int, int>> &nodes)
    {
        if (!node)
            return;
        nodes.emplace_back(col, row, node->value);
        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }

    bool isMirror(Node *n1, Node *n2)
    {
        if (n1 == nullptr && n2 == nullptr)
        {
            return true;
        }

        if (n1 == nullptr || n2 == nullptr)
        {
            return false;
        }

        return n1->value == n2->value && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }

    void inorder(Node *node, vector<int> &res)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->value);
        inorder(node->right, res);
    }

    void postorder(Node *node, vector<int> &res)
    {
        if (!node)
            return;
        postorder(node->left, res);
        postorder(node->right, res);
        res.push_back(node->value);
    }

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

    int diameterOfBinaryTree(Node *root)
    {
        dfs(root);
        return res;
    }
    void diameterOfBinaryTree()
    {
        cout << "Diameter Of Binary Tree: " << diameterOfBinaryTree(root) << endl;
    }

    bool hasPathSum(Node *root, int targetSum)
    {
        if (!root)
            return false;

        if (!root->left && !root->right)
        {
            return targetSum - root->value == 0;
        }

        targetSum -= root->value;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
    void hasPathSum(int value)
    {
        cout << boolalpha;
        cout << "Has Path Sum for (" << value << ") in the Tree: ";
        if (hasPathSum(root, value))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    bool isSymmetric(Node *root)
    {
        return isMirror(root->left, root->right);
    }
    void isSymmetric()
    {
        cout << boolalpha;
        cout << "Is Symmetric: " << isSymmetric(root) << endl;
    }

    vector<int> inorderTraversal(Node *root)
    {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    void inorderTraversal()
    {
        vector<int> res = inorderTraversal(root);
        cout << "Inorder Traversal: ";
        for (int num : res)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> postorderTraversal(Node *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }
    void postorderTraversal()
    {
        vector<int> res = postorderTraversal(root);
        cout << "Postorder Traversal: ";
        for (int num : res)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    int getMinimumDifference(Node *root)
    {
        vector<int> inOrder;
        inorder(root, inOrder);
        int minimum = INT_MAX;
        for (int i = 1; i < inOrder.size(); i++)
        {
            minimum = min(minimum, abs(inOrder[i] - inOrder[i - 1]));
        }
        return minimum;
    }
    void getMinimumDifference()
    {
        cout << "Minimum Difference in BST is: " << getMinimumDifference(root) << endl;
    }

    Node *invertTree(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
    void invertTree()
    {
        invertTree(root);
    }

    void solve(Node *root, int &cnt, int &ans, int k)
    {
        if (root == NULL)
            return;
        solve(root->left, cnt, ans, k);
        cnt++;
        if (cnt == k)
        {
            ans = root->value;
            return;
        }
        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(Node *root, int k)
    {

        int cnt = 0;
        int ans;
        solve(root, cnt, ans, k);
        return ans;
    }
    void kthSmallest(int k)
    {
        cout << "kth Smallest of " << k << " is: " << kthSmallest(root, k) << endl;
    }

    vector<vector<int>> verticalTraversal(Node *root)
    {
        vector<tuple<int, int, int>> nodes; // (col, row, val)
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prevCol = INT_MIN;

        for (const auto &t : nodes)
        {
            int col = get<0>(t);
            int row = get<1>(t);
            int val = get<2>(t);
            if (col != prevCol)
            {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }

        return res;
    }
    void verticalTraversal()
    {
        cout << "Vertical Traversal:\n";
        vector<vector<int>> result = verticalTraversal(root);
        for (const auto &col : result)
        {
            for (int val : col)
            {
                cout << val << " ";
            }
            cout << endl;
        }
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

    myBST->verticalTraversal();

    delete (myBST);
    return 0;
}