#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector <int> g,g2;
    int in,n;
    cout<<"N: ";
    cin>>n;
    for(int i=0;i<n;++i)
        {
            cin>>in;
            g.push_back(in);
        }
    for(auto i=g.begin();i!=g.end();++i)
        cout<<*i<<" ";
    cout<<"\n";

for(int i=0;i<n;++i)
    {g2=g;
    
    g2.erase(g2.begin()+i);
    cout<<"\nnumbers: ";
    for(auto i=g2.begin();i!=g2.end();++i)
        cout<<*i<<" ";

    }
    return 0;
}