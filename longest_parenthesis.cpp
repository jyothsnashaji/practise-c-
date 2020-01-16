/*Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

Input:
First line contains number of test cases T.  Each test case have one line string S of character '(' and ')' of length  N.*/
#include <bits/stdc++.h>
using namespace std;

void print_vector(string a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << " ";
    }
}

int longest_parenthesis(string a)
{
    stack<int> s;
    int max_ = 0, valid = 0;
    s.push(-1);
    for (int i = 0; i < a.size(); ++i)
    {

        if (a[i] == '(')
        {
            s.push(i);
        }
        else
        {
            s.pop();

            if (!s.empty())
            {
                max_ = max(max_, i - s.top());
            }
            else
            {
                s.push(i);
            }
        }
    }
    return max_;
}

int main()
{
    int t, n;
    char temp;
    string s;
    cin >> t;
    while (t--)
    {

        cin >> s;

        cout << longest_parenthesis(s)<<"\n";
    }

    return 0;
}