/*The government of virtualBit believes that the health of its citizens is the highest priority. It has devised an N-day health plan. During these N days, the citizens are encouraged to go to the gym for workouts.

A person may or may not go to the gym on any day. The people of virtualBit are a lazy lot, and they don't want to go to the gym for more than one consecutive day. Given the number of days N, print the number of ways the N-day plan can be completed.

Note that it is possible to not go to the gym on any day at all and still complete the plan.

Input

The first line contains T, the number of test cases.

Each test case contains a number N denoting the number of days.

Output

Each test case contains a single number denoting the number of ways by which the N-day plan may be completed.

Output your answer modulo 109+7.

Constraints

1 <= T <= 60000

1 <= N <= 1018 */


#include<iostream>
#include<math.h>
using namespace std;
long int N;
long int bal=(pow(10,9)+7);
void num_ways(long int n,long int ans[])
{
    if(n==0)
    {
        ans[0]=0;
        ans[1]=1;
        return;

    }
    num_ways(n/2,ans);
    long int f2n,f2n1;
    f2n=(2*ans[1]-ans[0]);
    if(f2n<0)
    {
        f2n+=bal;
    }
    f2n=(ans[0]*f2n)%bal;
    f2n1=((ans[0]*ans[0]) +(ans[1]*ans[1]))%bal;
    
    if(n%2==0)
    {
        ans[0]=f2n;
        ans[1]=f2n1;

    }
    else
    {
       ans[0]=f2n1;
       ans[1]=(f2n+f2n1)%bal;
    }
    
}

int main()
{
    long int t;
    long int ans[2];
    cin>>t;
    
    while(t--)
    {
        cin>>N;
        if(N<=2)
            cout<<N+1<<"\n";
        else
           { num_ways(N+2,ans);
            cout<<ans[0]<<"\n";
           }
    }
    return 0;
}