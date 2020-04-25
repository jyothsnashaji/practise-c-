/*You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. Your task is to find the stranger (celebrity) in party.
You will be given a square matrix M[][] where if an element of row i and column j  is set to 1 it means ith person knows jth person. You need to complete the function getId() which finds the id of the celebrity if present else return -1. The function getId() takes two arguments, the square matrix M and its size N.
Here, M[i][i] will be equal to zero.
Note: Expected time complexity is O(N) with constant extra space.*/

#include <bits/stdc++.h>
using namespace std;

int celebrity(int a[][500],int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(j==n)
                return i;
            if(!((i!=j && a[j][i] && !a[i][j])|| i==j))
                break;            
                                   
        }
    }
    return -1;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[500][500];
        for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
            cin >> a[i][j];

        cout << celebrity(a,n) << "\n";
       // cout << maxPoint(a,0,n-1) << "\n";

    }
    return 0;
}