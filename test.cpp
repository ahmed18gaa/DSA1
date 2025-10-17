#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
        return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++)
    {
        int profit = prices[i] - minPrice;
        maxProfit = max(maxProfit, profit);

        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
}

int findMiddleIndex(vector<int> &nums)
{
    int n = nums.size();
    int left_sum = 0;
    int right_sum = 0;
    for (int i = 0; i < n; i++)
    {
        right_sum += nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        right_sum -= nums[i];
        if (left_sum == right_sum)
        {
            return i;
        }
        left_sum += nums[i];
    }
    return -1;
}

int *f(int &n) // return pointer + size via reference
{
    n = 5;
    int *a = new int[n]{1, 2, 3, 4, 5}; // allocated on heap
    return a;                           // safe to return
}
int main()
{
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    // cout << maxProfit(prices) << endl;
    // vector<int> num = {2, 3, -1, 8, 4};
    // cout << findMiddleIndex(num) << endl;
    int n;
    int *p = f(n);

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }

    delete[] p; // free memory
    return 0;
}