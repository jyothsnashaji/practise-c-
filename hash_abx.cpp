/* given x, find all pairs in a array that sums up to x
*/

#include<bits/stdc++.h>
using namespace std;

void check_triplets(vector <int> a, int x)
{
    unordered_set <int> s;
    for(auto i=a.begin();i!=a.end();++i)
    {
        if(s.find(x-*i)!=s.end())
            cout<<*i<<" "<<x-*i<<"\n";
        s.insert(*i);
    }
} 
int main()
{
    int t,n,temp;
    vector <int> a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>temp;
            a.push_back(temp);
        }
        cin>>temp;
        check_triplets(a,temp);
        
    }

    return 0;
}