/*Given a paper of size A x B. Task is to cut the paper into squares of any size. Find the minimum number of squares that can be cut from the paper.*/

#include <bits/stdc++.h>
using namespace std;

int mincutOpt(int a, int b)
{
    int ans[a + 1][b + 1];
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (i == j)
                ans[i][j] = 1;
            else 
                ans[i][j] = INT16_MAX;
            for (int k = 1; k < i; ++k)
                ans[i][j] = min(ans[i][j], ans[k][j] + ans[i - k][j]);
            for (int k = 1; k < j; ++k)
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[i][j - k]);
           // cout << ans[i][j] << " ";
        }
       // cout << "\n";
    }

    return ans[a][b];
}

int mincut(int a, int b)
{
    int minv;
    cout << a << " " << b << "..";
    if (a == b)
        minv = 1;
    else
        minv = INT16_MAX;
    for (int i = a - 1; i > 0; --i)
        minv = min(minv, mincut(a - i, b) + mincut(i, b));
    for (int i = b - 1; i > 0; --i)
        minv = min(minv, mincut(a, b - i) + mincut(a, i));
    return minv;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << mincutOpt(a, b) << "\n";
    }
}