/*Given weights and values related to n items and the maximum capacity allowed for these items. What is the maximum value we can achieve if we can pick any weights any number of times for a total allowed weight of W?

Input:
The first line of input contains an integer denoting the number of test cases. Then T test cases follow . Each test case contains two integers N and W denoting the number of items and the total allowed weight. In the next two lines are space separated values of the array denoting values of the items (val[]) and their weights (wt[]) respectively.

Output:
For each test case, in a new line, print the  maximum value which we can achieve if we can pick any weights any number of times for a bag of size W.

Constraints:
1 <= T <= 100
1 <= N, W <= 103
1 <= wt[], val[] <= 100

Example:
Input:
2
2 3
1 1
2 1 
4 8
1 4 5 7
1 3 4 5
Output:
3
11*/


#include <bits/stdc++.h>
using namespace std;

int maxValueOptimised(vector<int> v, vector<int> w, int W)
{
    vector<int> dp(W+1);
    dp[0] = 0;
    for (int i = 1; i < W+1; ++i)
    {
        dp[i] = 0;
        for (int j = 0; j < v.size(); ++j)
        {
            if (w[j] <= i)
                dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
        }
        cout<<dp[i]<<" ";
    }
    return dp[W];
}

int maxValue(vector<int> v, vector<int> w, int W)
{
    if (W <= 0)
        return 0;
    int maxval = INT16_MIN;
    for (int i = 0; i < v.size(); ++i)
    {
        if (w[i] <= W)
            maxval = max(maxval, maxValue(v, w, W - w[i]) + v[i]);
    }
    return maxval;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, W, temp;
        vector<int> w, v;
        cin >> n >> W;
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            w.push_back(temp);
        }
        cout << maxValueOptimised(v, w, W) << "\n";
    }
}