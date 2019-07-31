/*Check Repetition in a string*/

#include<bits/stdc++.h>
using namespace std;

string rep(string str)
{
    unordered_set <char> hash;
    

    for(int i=0;i!=str.size();++i)
    {
        if(hash.find(str[i])==hash.end())
            hash.insert(str[i]);
        else
            return "There is repeition";
    }

    return "No Repetition";
}

int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<rep(str);
    }
    return 0;
}