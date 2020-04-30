/*Given a string you need to print the size of the longest possible substring that has exactly k unique characters. If there is no possible substring print -1.
Example
For the string aabacbebebe and k = 3 the substring will be cbebebe with length 7.*/

#include <bits/stdc++.h>
using namespace std;

void remove(unordered_map<char, int> &hash, char c)
{
    if (hash[c] == 1)
        hash.erase(c);
    else
    {
        hash[c]--;
    }
}

int maxUnique(string s, int k)
{
    unordered_map<char, int> hash, temp;
    for (int i = 0; i < s.size(); ++i)
        hash[s[i]]++;
    if (hash.size() < k)
        return -1;
    if (hash.size() == k)
        return s.size();
    for (int win = s.size(); win >= k; --win)
    {
        temp = hash;
        for (int i = 0; i + win <= s.size(); ++i)
        {
            //cout<<s.substr(i,win)<<"..";
            if (hash.size() == k)
                {
                    return win;}
            remove(hash, s[i]);
            hash[s[i + win]]++;
        }
        remove(temp, s[win - 1]);
        hash = temp;
    }
}

int main()
{
    int t, k;

    cin >> t;
    while (t--)
    {
        string s;
        cin >> s >> k;
        //cout << dfs(s1, s2) << "\n";
        cout << maxUnique(s, k) << "\n";
    }
    return 0;
}