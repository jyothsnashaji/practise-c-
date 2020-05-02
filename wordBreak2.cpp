/*Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].*/
#include <bits/stdc++.h>
using namespace std;

void addBreak(unordered_set<string> dict, string s, string res)
{
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        if (dict.find(s.substr(0, i + 1)) != dict.end())
        {
            if (i == n - 1)
                cout << "(" << res + s.substr(0, i + 1) << ")";
            else
                addBreak(dict, s.substr(i + 1, n - i + 1), res + s.substr(0, i + 1) + " ");
        }
    }
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
        addBreak(dict, s, "");
        cout << "\n";
    }
}
