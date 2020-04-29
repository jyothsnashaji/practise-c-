

#include <bits/stdc++.h>
using namespace std;

int minTimeOpt(vector<int> a, int start, int p)
{
    if (p == 1)
        return accumulate(a.begin() + start, a.end(), 0);
    int n = a.size();
    vector<vector<int>> sum(n, vector<int>(n, 0));
    vector<vector<int>> ans(n, vector<int>(p + 1, INT16_MAX));

    for (int i = 0; i < n; ++i)
    {
        sum[i][i] = a[i];
        for (int j = i + 1; j < n; ++j)
            sum[i][j] = sum[i][j - 1] + a[j];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        ans[i][1] = sum[i][n - 1];
        for (int j = 2; j <= p; ++j)
        {
           // cout << i << " " << j << "//";
            for (int k = i; k < n; ++k)
            {
                ans[i][j] = min(ans[i][j], max(sum[0][k - 1], ans[k][j - 1]));
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