/*Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].*/
#include<bits/stdc++.h>
using namespace std;



long  int max_diff(vector <long long int> a)
{    long int n=a.size(),win,i;
    for( win=n-1;win>=0;--win)
        for( i=0;i+win<n;++i)
            if(a[i]<=a[i+win])
                return win;
    return 0;
}
 int main()
{

    long int t, n;
    cin>>t;
    while(t--)
    {
       cin>>n; 
       vector <long long int> a(n);
        for(long  int i=0;i<n;++i)
            cin>>a[i];
        cout<<max_diff(a)<<"\n";


    
    }
        

    return 0;
}