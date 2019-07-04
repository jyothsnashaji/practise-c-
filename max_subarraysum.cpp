/*Find the contiguous subarray within an array (containing at least one number) which has the largest sum. */

#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;

vector<int> a;

int max_sum_brute_force() //O(n2)
{
    int sum=a[0];
    for (auto i = a.begin(); i < a.end(); i++)
    {
        for(auto j=i;j<a.end();++j)
        {
            sum=max(sum,accumulate(i,j,0));
        }
    }
    
    return sum;

}
int max_sum_divide_and_conquer(int l, int r)//O(nlogn)
{
    if(l==r)
    {
        return a[l];
    }
    int m= (l+r)/2;
    int left_sum=0;
    int sum=INT32_MIN;
    for(int i=m;i>=l;--i)
    {
        left_sum=left_sum+a[i];
        sum=max(sum,left_sum);

    }
    left_sum=sum;
    int right_sum=0;
    sum=INT32_MIN;
    for(int i=m+1;i<=r;++i)
    {
        right_sum=right_sum+a[i];
        sum=max(sum,right_sum);

    }
    right_sum=sum;
    //cout<<"\n"<<l<<" "<<left_sum<<" "<<m<<" "<<right_sum<<" "<<r;
    return max(max(max_sum_divide_and_conquer(l,m),max_sum_divide_and_conquer(m+1,r)),left_sum+right_sum);
}

int max_sum() //O(n)
{
    int max_here=0;
    int max_till=0;
    for(auto i=a.begin();i!=a.end();++i)
    {
        max_till=max_till+*i;
        if(max_till<0)
        {
            max_till=0;
        }
        else if(max_till>max_here)
        {
            max_here=max_till;
        }
    
        
    }
    if (all_of(a.begin(),a.end(),[](int x){return x<0;}))
    {
        max_here=*max_element(a.begin(),a.end());
    }
    return max_here;
}

int main()
{
    int n;
    cin>>n;
    int temp;
    for (int i=0;i<n;++i)
    {
        cin>>temp;
        a.push_back(temp);
    }

    cout<<max_sum();
    return 0;
}