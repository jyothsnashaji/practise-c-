
/*Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T contains lowercase english alphabets.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each test contains 2 lines having a string S and next line contains text T.

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be done then print -1.*/
#include <bits/stdc++.h>
using namespace std;

void add(unordered_map<char, int> &h, char i)
{
    h[i]++;
}

void remove(unordered_map<char, int> &h, char i)
{
    if (h[i] > 1)
        h[i]--;
    else
        h.erase(i);
}
void print(unordered_map<char, int> umap)
{
    for (auto itr = umap.begin(); itr != umap.end(); itr++)

    {

        cout << itr->first << "  " << itr->second << "..";
    }
    cout << "\\";
}

bool contains(string s, string t)
{
    unordered_map<char, int> hash;
    for (int i = 0; i < s.size(); ++i)
        add(hash, s[i]);

    for (int i = 0; i < t.size(); ++i)
    {
        if (hash.find(t[i]) != hash.end())
            remove(hash, t[i]);
        else
            return false;
    }
    return true;
}
string window(string s, string t)
{
    if (t.size() > s.size() || !contains(s, t))
        return "-1";

    unordered_map<char, int> hash, temp;
    string str;
    int start, end, i;
    for (i = 0; i < t.size(); ++i)
        hash[t[i]]++;

    start = -1;
    end = s.size();

    while (start <= end && end <= s.size())
    {
        temp = hash;
        start=start+1;
        i = start;
        //cout << s.substr(start, end - start + 1) << "..";

        while (temp.size() && i <= end)
        {
            if (temp.find(s[i]) != temp.end())
                remove(temp, s[i]);
            ++i;
        }
        if (!temp.size())
        {
            end = i - 1;
            str = s.substr(start, end - start + 1);
        }
        else
        {
            end = i;
        }

    }
    return str;
}

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        string s, txt;
        cin >> s >> txt;
        cout << window(s, txt) << "\n";
        // cout << contains(s, txt) << "\n";
    }
}
