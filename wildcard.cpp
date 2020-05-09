/*Given a string containing of ‘0’, ‘1’ and ‘?’ wildcard characters, generate all binary strings that can be formed by replacing each wildcard character by ‘0’ or ‘1’.*/

#include <bits/stdc++.h>
using namespace std;

void strings(string s, string res, int start)
{
    //cout << start << " " << res << "..";
    int i, n = s.size();

    for (i = start; i < n; ++i)
    {
        if (s[i] != '?')
            res = res + s[i];
        else
        {
            break;
        }
    }
    if (i == n)
        cout << res << " ";
    else
    {
        strings(s, res + '0', i + 1);
        strings(s, res + '1', i + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        strings(s, "", 0);
        cout << "\n";
    }
}