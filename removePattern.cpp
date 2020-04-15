/*Given a string, eliminate all “b” and “ac” in the string, replace them in-place and iterate over the string once.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string of length N.

Output:
Print the resultant substring after removing 'b' and 'ac' from string.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 200

Example:
Input:
2
acbac
aababc

Output:

aaac*/


#include<bits/stdc++.h>
using namespace std;

string removePattern(string s)
{
    int i=0;
    while(i<s.size())
    {
       if(s[i]=='b')
        {
            s.erase(s.begin()+i);
        }
        else if(s[i]=='a'&& i<s.size()-1 && s[i+1]=='c')
        {
            s.erase(s.begin()+i,s.begin()+i+2);
        }
        else
        {
            ++i;
        }
        
        
    }
    return s;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<removePattern(s)<<"\n";
    }
}