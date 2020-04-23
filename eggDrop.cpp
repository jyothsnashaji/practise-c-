/*Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

*/
#include <bits/stdc++.h>
using namespace std;

int eggDropOpt(int n, int k)
{
    int a[n+1][k + 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (j < 2 || i == 1)
                a[i][j] = j;
            else
            {
                a[i][j] = INT16_MAX;
                for (int l = 1; l <= j; ++l)
                    a[i][j] = min(a[i][j], max(a[i - 1][l - 1] + 1, a[i][j - l] + 1));
            }// cout<<a[i][j]<<" ";
        }
        //cout<<"\n";
    }
/*    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }*/
    return a[n][k];
}

int eggDrop(int n, int k)
{
    if (k < 2 || n == 1)
        return k;
    int minv = INT16_MAX;
    for (int i = 1; i <= k; ++i)
    {
        cout << n << " " << k - i << "..";
        minv = min(minv, max(1 + eggDrop(n, k - i), 1 + eggDrop(n - 1, i - 1)));
    }

    return minv;
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << eggDropOpt(n, k) << "\n";
    }
}
