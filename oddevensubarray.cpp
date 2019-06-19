/*You are given an array A of N positive integer values. A subarray of this array is called Odd-Even subarray if the number of odd integers in this subarray is equal to the number  of even integers in this subarray.

Find the number of Odd-Even subarrays for the given array.

Input Format:
The input consists of two lines.

First line denotes N - size of array.
Second line contains N space separated positive integers denoting the elements of array A.

Output Format:
Print a single integer, denoting the number of Odd-Even subarrays for the given array. */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long int n;
vector <long int> a;
vector <long int> hash_n,hash_p;

void print_vect(vector <long int> a)
{
    for(auto i=a.begin();i!=a.end();++i)
    {
        cout<<*i<<" ";
    }

}

long int check_sub()
{

    long int ans=0;
    long int diff=0;
    hash_n.resize(a.size()+1);
    hash_p.resize(a.size()+1);

    fill(hash_n.begin(),hash_n.end(),0);
    fill(hash_p.begin(),hash_p.end(),0);

    //print_vect(hash_n);

    hash_p.at(0)=1;

    for (long int i=0;i<n;++i)
    {
        if(a.at(i)%2==0)
        {
            diff--;
        }
        else
        {
            diff++;
        }
        if (diff<0)
        {
            ans+=hash_n.at(-diff);
            hash_n.at(-diff)++;
        }
        else
        {
            ans+=hash_p.at(diff);
            hash_p.at(diff)++;
        }
        
       
    }
    
     return ans;
}


int main()
{
    
    long int temp;
    
    cin>>n;
    for(long int i=0;i<n;++i)
    {
        cin>>temp;
        a.push_back(temp);
    }

    cout<<check_sub();

    
    return 0;
}