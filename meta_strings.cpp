/* Given two strings, the task is to check whether these strings are meta strings or not. Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.

*/

#include<bits/stdc++.h>
using namespace std;

bool check_meta(string str1, string str2)
{

    if (str1.length()!=str2.length() || str1==str2)
        return false;
    auto mis=mismatch(str1.begin(),str1.end(),str2.begin());
    auto mis2=mismatch(mis.first+1,str1.end(),mis.second+1);
    iter_swap(mis.first,mis2.first);
    if (str1==str2)
        return true;
    return false;



}

int main()
{
    int t;
    string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        cout<<check_meta(str1,str2);
        
    }

    return 0;
}