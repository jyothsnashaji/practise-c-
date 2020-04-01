/*Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is a string, which contains only I's and D's in capital letter.

Output:
Print the minimum number following that pattern.

Constraints:
1 ≤ T ≤ 100
1 ≤ Length of String ≤ 8

Example:
Input
5
D
I
DD
IIDDD
DDIDDIID

Output
21
12
321
126543
321654798*/
#include <bits/stdc++.h>
using namespace std;

void minPattern(string s)
{
    int n = s.size();
    int a[n + 1];
    for (int i = 0; i < n +1; ++i)
        a[i] = i+1;
    int i = 0;
    while (i < n)
    {
        if (s[i] == 'I')
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                if (i)
                    --i;
            }
            else
            {
                ++i;
            }
            
        }
        else
        {
            if (a[i] < a[i + 1])
            {
                swap(a[i], a[i + 1]);
                if (i)
                    --i;
            }
            else
            {
                ++i;
            }
            
        }
        
    }
    for(int i=0;i<n+1;++i)
        cout<<a[i];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        minPattern(s);
        cout << "\n";
    }
}