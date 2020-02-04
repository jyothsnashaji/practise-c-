#include<bits/stdc++.h>

using namespace std;

bool isInterleave(string a, string b, string c) 
{
    //cout<<a<<" "<<b<<" "<<c<<"\n";
    if(c.size()!=a.size()+b.size())
    {
        return false;
    }
    if (!c.size())
    {
        return true;
    }

    if(!a.size())
    {
        return !b.compare(c);
    }

    if(!b.size())
    {
       return !a.compare(c);
    }

    if(a[0]==c[0] && b[0]==c[0])
    {
        return isInterleave(a.substr(1),b,c.substr(1))||isInterleave(a,b.substr(1),c.substr(1));
    }

    else if (a[0]==c[0])
    {
        return isInterleave(a.substr(1),b,c.substr(1));
    }

    else if(b[0]==c[0])
    {
       return isInterleave(a,b.substr(1),c.substr(1));
    }
   else
   {
       return false;
   }
   
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        cout<<isInterleave(a,b,c)<<"\n";

    }
}