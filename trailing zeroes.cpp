/*
Input First line of input contains an integer T number of test cases. 
Each test case contains an integer M (1 ≤ M ≤ 100,000) — the required number of trailing zeroes in factorial.

Output First print k — the number of values of n such that the factorial of n ends with m zeroes. Then print these k integers in increasing order.
*/
#include<iostream>
#include<math.h>
using namespace std;

long int calz(long int m)
{
    long int c=0;
    while(m)
    {
        c=c+m/5;
        m=m/5;
    }
    return c;
}

int main()
{
    int t;
    long int m;
    
    cin>>t;
    while(t--)
    {
        cin>>m;
        int i=0;
       
        
        int low,high,mid,c;
        low=0;
        high=5*m;

        while(low<=high)
        {   
            mid=(low+high)/2;
            c=calz(mid);
            if(c==m)
            {
                low=mid-mid%5;
                break;
            }
            if(c>m)
            {
                high=mid-1;
            }
            else
            {
             low=mid+1;   
            }
        
        }
        i=0;
        //cout<<low<<" "<<high;
        if(low>high)
            cout<<"\n0";
        else
            {
            cout<<"\n5\n";
            while(i<5)
                {
                    cout<<low+i++<<" ";

                }
            }
    }
    return 0;
}