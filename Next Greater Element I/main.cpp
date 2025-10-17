#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> res(nums1.size(), -1);
    stack<int> st;
    unordered_map<int, int> umap;

    for (int i = 0; i < nums2.size(); i++)
    {
        int element = nums2[i];

        while (!st.empty() && element > st.top())
        {
            umap[st.top()] = element;
            st.pop();
        }
        st.push(element);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        int ele = nums1[i];
        if (umap.find(ele) != umap.end())
        {
            res[i] = umap[ele];
        }
    }
    return res;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
