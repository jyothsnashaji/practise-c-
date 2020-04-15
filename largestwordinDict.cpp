/*Giving a dictionary and a string ‘str’, your task is to find the longest string in dictionary of size x which can be formed by deleting some characters of the given ‘str’.

Examples:

Input : dict = {"ale", "apple", "monkey", "plea"}   
        str = "abpcplea"  
Output : apple

Input  : dict = {"pintu", "geeksfor", "geeksgeeks", 
                                        " forgeek"} 
         str = "geeksforgeeks"
Output : geeksgeeks
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(string &s1, string &s2)
{
    return s1.size() > s2.size();
}
bool issubSeq(string a, string b, int i, int j)
{
    if (j == b.size())
        return true;
    if (i == a.size())
        return false;
    if (a[i] == b[j])
        return issubSeq(a, b, ++i, ++j);
    else

        return issubSeq(a, b, ++i, j);
}

string findLargest(vector<string> dict, string s)
{
    for (int i = 0; i < dict.size(); ++i)
    {
        if (issubSeq(s, dict[i], 0, 0))
            return dict[i];
    }
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        string s;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;
        sort(dict.begin(), dict.end(), compare);
        cout << findLargest(dict, s) << "\n";
    }
}
