/*You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.*/

#include <bits/stdc++.h>
using namespace std;

int maxPointOpt(vector<int> a)
{
    int n = a.size();
    int maxp[n][n], sum[n][n];
    for (int i = n-1; i>=0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i > j)
            {
                maxp[i][j] = 0;
                sum[i][j] = 0;
            }
            else if (i==j)
            {
                sum[i][j]=a[j];
                maxp[i][j] = max(a[i] ,a[j] );
            }
            else
           {   sum[i][j]=sum[i][j-1]+a[j];
                maxp[i][j] = max(a[i] + sum[ i + 1][  j ] - maxp[i + 1][j],
                              a[j] + sum[i] [j-1]- maxp[i][j - 1]);
            }
        }
    }
    return maxp[0][n-1];
}

int maxPoint(vector<int> a, int start, int end)
{
    if (start > end)
        return 0;
            cout<<"("<<start<<","<<end<<")";

    return max(a[start] + accumulate(a.begin() + start + 1, a.begin() + end + 1, 0) - maxPoint(a, start + 1, end),
               a[end] + accumulate(a.begin() + start, a.begin() + end, 0) - maxPoint(a, start, end - 1));
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        cout << maxPointOpt(a) << "\n";
       // cout << maxPoint(a,0,n-1) << "\n";

    }
    return 0;
}