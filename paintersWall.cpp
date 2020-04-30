/*Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An]. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Input:
The first line consists of a single integer T, the number of test cases. For each test case, the first line contains an integer k denoting the number of painters and integer n denoting the number of boards. Next line contains n- space separated integers denoting the size of boards.

Output:
For each test case, the output is an integer displaying the minimum time for painting that house.

Constraints:
1<=T<=100
1<=k<=30
1<=n<=50
1<=A[i]<=500

Example:
Input:
2
2 4
10 10 10 10
2 4
10 20 30 40
Output:
20
60*/

#include <bits/stdc++.h>
using namespace std;

int minTimeOpt(vector<int> a, int start, int p)
{
    if (p == 1)
        return accumulate(a.begin() + start, a.end(), 0);
    int n = a.size();
    vector<vector<int>> sum(n, vector<int>(n, 0));
    vector<vector<int>> ans(n+1, vector<int>(p + 1, INT16_MAX));

    for (int i = 0; i < n; ++i)
    {
        sum[i][i] = a[i];
        ans[n][i] = 0;

        for (int j = i + 1; j < n; ++j)
            sum[i][j] = sum[i][j - 1] + a[j];
    }
    for (int i = n-1; i >= 0; --i)
    {
        ans[i][1] = sum[i][n - 1];
        for (int j = 2; j <= p; ++j)
        {
            ans[n][j]=0;
            // cout << i << " " << j << "//";
            for (int k = i; k < n; ++k)
            {
                ans[i][j] = min(ans[i][j], max(sum[i][k], ans[k + 1][j - 1]));
                //cout << i << " " << j << " " << k << "..";
            }
        }
    }
    return ans[0][p];
}

int minTime(vector<int> a, int start, int p)
{
    if (!(start <= a.size() && p))
        return 0;
    if (p == 1)
        return accumulate(a.begin() + start, a.end(), 0);
    int mint = INT16_MAX;
    for (int i = start; i <= a.size(); ++i)
        mint = min(mint, max(accumulate(a.begin() + start, a.begin() + i + 1, 0), minTime(a, i + 1, p - 1)));
    //cout<<start<<" "<<end<<" "<<p<<" "<<mint<<"..";
    return mint;
}

int main()
{
    int t, n, p;

    cin >> t;
    while (t--)
    {
        cin >> p >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        //cout << dfs(s1, s2) << "\n";
        cout << minTimeOpt(a, 0, p) << "\n";
    }
    return 0;
}