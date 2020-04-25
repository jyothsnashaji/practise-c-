
/*We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f (2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f (2, 7) = 2.

You are given an array of N integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.*/
#include <bits/stdc++.h>
using namespace std;

int fOpt(long int a[], int n)
{
    int count[32];
    for(int i=0;i<32;++i)
    {
        count[i]=0;
        for(int j=0;j<n;++j)
        {
            if(a[j]&1)
                count[i]++;
            a[j]=a[j]>>1;
        }
    }
    int sum=0;
    for(int i=0;i<32;++i)
    {
        sum=sum+count[i]*(n-count[i])*2;
    }
    return sum%(int(pow(10,9)+7));
}

int f(long int a[], int n)
{
    int c = 0, t;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {

            t = a[i] ^ a[j];
            while (t)
            {
                if (t & 1)
                    c++;
                //cout << !(t & 1) << "..";
                t = t >> 1;
            }
        }
    return 2 * c;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

       // cout << f(a, n) << "\n";
         cout << fOpt(a,n) << "\n";
    }
    return 0;
}