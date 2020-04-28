
/*Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the number of key.

Output:
Print maximum number of A's. Print -1, if N is greater than 75.*/
#include <bits/stdc++.h>
using namespace std;

long int maxAOpt(int n)
{
    if (n > 75)
        return -1;
    long int maxa[n+1];
    for (int i = 1; i <= n; ++i)
    {
        maxa[i] = i;
        for (int j = i - 3; j > 0; --j)
            maxa[i] = max(maxa[i], (i - j - 1) * maxa[j]);
    }
    return maxa[n];
}

long int maxA(int n)
{
    if (n > 75)
        return -1;
    long int maxa = n;
    for (int i = n - 3; i > 0; --i)
        maxa = max(maxa, (n - i - 1) * maxA(i));
    return maxa;
}

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;

        //cout << dfs(s1, s2) << "\n";
        cout << maxAOpt(n) << "\n";
    }
    return 0;
}