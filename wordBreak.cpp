/*Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0*/
#include <bits/stdc++.h>
using namespace std;

bool check(unordered_set<string> dict, string s, int start, int end) //brute force
{

    if (dict.find(s.substr(start, end - start + 1)) != dict.end())
    {
        return true;
    }
    else
    {
        for (int i = start; i < end; ++i)
        {
            if (check(dict, s, start, i) && check(dict, s, i + 1, end))
            {
                return true;
            }
        }

        return false;
    }
}
bool find_substring(unordered_set<string> dict, string s, int start, int end)
{
    if (dict.find(s.substr(start, end - start + 1)) != dict.end())
    {
        return true;
    }
    return false;
}

bool check_optimised(unordered_set<string> dict, string s) //brute force
{
    bool check[1000][1000];
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        check[i][i] = find_substring(dict, s, i, i);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            check[i][j] = find_substring(dict, s, i, j);
            if (!check[i][j])
            {
                for (int k = i; k < j + 1; ++k)
                {
                    if (check[i][k] && check[k + 1][j])
                    {
                        check[i][j] = true;
                        break;
                    }
                }
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << check[i][j] << " ";
        }
        cout << "\n";
    }*/
    return check[0][n - 1];
}

int main()
{
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        unordered_set<string> dict;
        string s;
        cin >> n;
        while (n--)
        {
            cin >> s;
            dict.insert(s);
        }
        cin >> s;
        cout << check_optimised(dict, s) << "\n";
    }
}
