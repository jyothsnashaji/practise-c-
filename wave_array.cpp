/*Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....*/

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector <int> a)
{
    for(auto i=a.begin();i!=a.end();++i)
    {
        cout<<*i<<" ";
    }
}

vector <int> wave(vector <int> a)
{
    sort(a.begin(),a.end());
    for(auto i=a.begin();i!=a.end()&&i+1!=a.end();i=i+2)
    {
       iter_swap(i,i+1);
    }
    return a;
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
    print_vector(wave(a));
    return 0;
}