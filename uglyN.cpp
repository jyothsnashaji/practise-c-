/*Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

*/

#include <bits/stdc++.h>
using namespace std;

bool checkUgly(int num)
{
    // cout << num << " ";
    while (!(num % 2))
    {
        num = num / 2;
    }
    while (!(num % 3))
    {
        num = num / 3;
    }
    while (!(num % 5))
    {
        num = num / 5;
    }
    // cout << num << "..";
    return (num == 1) ? true : false;
}

int uglyN(int n)
{
    int i = 0, num = 0;
    while (i < n)
    {
        ++num;
        if (checkUgly(num))
        {
            ++i;
        }
    }
    return num;
}

long int uglyNOpt(int n)
{
    long int a[n];
    a[0] = 1;
    int next2 = 0, next3 = 0, next5 = 0;
    long int u2 = 2, u3 = 3, u5 = 5;
    for (long int i = 1; i < n; ++i)
    {
        a[i] = min(u2, min(u3, u5));
        if (a[i] == u2)
        {
            ++next2;
            u2 = a[next2] * 2;
        }
        if (a[i] == u3)
        {
            ++next3;
            u3 = a[next3] * 3;
        }
        if (a[i] == u5)
        {
            ++next5;
            u5 = a[next5] * 5;
        }
    }
    return a[n - 1];
}
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << uglyNOpt(n) << "\n";
    }
    return 0;
}