/*Given an array A of N positive integers and another number X. Determine whether or not there exist two elements in A whose sum is exactly X.*/

#include <bits/stdc++.h>
using namespace std;

string pairs(vector <int> a,int x)
{
    unordered_map <int,int> h;
    int n=a.size();
    for (int i=0;i<n;++i)
    {
        if(h.find(x-a[i])!=h.end())
            return "Yes";
        else
        {
            h[a[i]]++;
        }
        
    }
    return "No";

}

int main()
{

    int t, n,x;
    cin >> t;
    while (t--)
    {

        cin >> n>>x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << pairs(a,x) << "\n";
    }
    return 0;
}