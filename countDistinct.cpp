/*Given an array A[] of size N and an integer K. Your task is to complete the function countDistinct() which prints the count of distinct numbers in all windows of size k in the array A[].

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integers N and K. Then in the next line are N space separated values of the array A[].

Output:
For each test case in a new line print the space separated values denoting counts of distinct numbers in all windows of size k in the array A[].*/

#include <bits/stdc++.h>

using namespace std;

void countDistinct(int a[], int n, int k)
{
    int c = 0;
    unordered_map<int, int> hashmap;
    for(int i=0;i<n;++i)
    {

        if(hashmap.find(a[i])!=hashmap.end())
        {
            hashmap[a[i]]++;
         
        }
        else
        {
            hashmap.insert(make_pair(a[i],1));
            ++c;
        }
        

        if (i>k-2)
        {
            hashmap[a[i+1-k]]--;
            cout<<c<<" ";
            
            if(!hashmap[a[i+1-k]])
            {
                hashmap.erase(a[i+1-k]);
                --c;
            }
            
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        countDistinct(a, n, k);
        cout << "\n";
    }
}