/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd*/
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return temp == s ? true : false;
}
int makePalindromeOpt(string s)
{
    if (isPalindrome(s))
        return 0;

    int mincost[s.size()][s.size()];
    int n = s.size();
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i >= j)
            {
                mincost[i][j] = 0;
                continue;
            }
           // cout << s.substr(i, j - i + 1) << "..";
            if (isPalindrome(s.substr(i, j - i + 1)))
                mincost[i][j] = 0;
            else if (s[i] == s[j])
                mincost[i][j] = mincost[i + 1][j - 1];
            else
                mincost[i][j] = min(1 + mincost[i + 1][j], min(1 + mincost[i][j - 1], 2 + mincost[i + 1][j - 1]));
        }
        //cout << "\n";
    }
  /*  for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << mincost[i][j] << " ";
        cout << "\n";
    }*/
    return mincost[0][n - 1];
}

int makePalindrome(string s, int start, int end)
{
    if (start >= end)
        return 0;
    //cout<<start<<" "<<end<<"..";
    string temp = s;
    reverse(temp.begin(), temp.end());
    if (temp == s)
        return 0;
    if (s[start] == s[end])
        return makePalindrome(s, start + 1, end - 1);
    else
        return min(1 + makePalindrome(s, start + 1, end), min(1 + makePalindrome(s, start, end - 1), 2 + makePalindrome(s, start + 1, end - 1)));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << makePalindromeOpt(s) << "\n";
        //cout << makePalindrome(s,0,s.size()-1) << "\n";
    }
}
