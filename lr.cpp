/*You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;



int max_lr_()
{
     long int max_lr=0;
    
   
    long int mod=1000000007;
    int l=0,r=0;
    
    for(auto i=A.begin();i!=A.end();++i)
    {
        l=0;
        r=0;
        for(auto it=i-1;it!=A.begin()-1;--it)
        {
            if(*it>*i)
            {
                l=it-A.begin();
                break;
            }
        }
        if(l==0)
        continue;
        for(auto it=i+1;it!=A.end();++it)
        {
            if(*it>*i)
            {
                r=it-A.begin();
                break;
            }
        }
        if(r==0)
        continue;
        //cout<<"\n"<<l<<" "<<r;
        max_lr=max(max_lr,(l*r)%mod);
    }

    return max_lr;
}

int main()
{ 
    int n,temp;
    
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>temp;
        A.push_back(temp);
    }
    cout<<max_lr_();
    return 0;
}