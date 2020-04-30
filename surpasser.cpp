/*A surpasser of an element of an array is a greater element to its right, therefore x[j] is a surpasser of x[i] if i < j and x[i] < x[j]. The surpasser count of an element is the number of surpassers.
Given an array of distinct integers, for each element of the array find its surpasser count i.e. count the number of elements to the right that are greater than that element.*/
#include <bits/stdc++.h>
using namespace std;

void surpasser(vector<int> a)
{
    int c;
    for (int i = 0; i < a.size(); ++i)
    {
        c = 0;
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[j] > a[i])
                ++c;
        }
        cout << c << " ";
    }
}

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        //cout << dfs(s1, s2) << "\n";
        surpasser(a);
        cout << "\n";
    }
    return 0;
}