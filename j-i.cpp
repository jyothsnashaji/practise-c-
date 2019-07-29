/*Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.*/

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector <int> a)
{
    for(auto i=a.begin();i!=a.end();++i)
    {
        cout<<*i<<" ";
    }
}


int max_diff(vector <int> a)
{    vector <pair<int,int>> temp;
    vector <int> index,index_max;
    for(auto i=a.begin();i!=a.end();++i)
    {
        temp.push_back(make_pair(*i,i-a.begin()));
    }
    sort(temp.begin(),temp.end());
    for(auto i=temp.begin();i!=temp.end();++i)
        index.push_back((*i).second);
    int max_i=*(index.end()-1),max_=0;
    for(int i=a.size()-2;i>=0;--i)
    {
       
        max_=max(max_,max_i-index[i]);
       
        max_i=max(max_i,index[i]);   
        
    }
    //print_vector(index);
    //print_vector(index_max);

    
    
    return max(0,max_);


}
int main()
{

    int n;
    cin>>n;
    vector <int> a;
    int temp;
    while(n--)
    {
        cin>>temp;
        a.push_back(temp);
    }
    cout<<max_diff(a);
    return 0;
}