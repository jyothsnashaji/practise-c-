#include <bits/stdc++.h>

using namespace std;

bool findTriplets(int arr[], int n)
{
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        a.push_back(arr[i]);
    }
    sort(a.begin(), a.end());

    if ((all_of(a.begin(), a.end(), [](int x) { return x > 0; })) || (all_of(a.begin(), a.end(), [](int x) { return x < 0; })))
    {
        return 0;
    }
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        for (auto j = i+1; j != a.end(); ++j)
        {
            int sum = -(*i + *j);
            if (sum==*i || sum==*j)
            {
               if (count(a.begin(),a.end(),sum)>1)
                    return true;
                else
                    continue;
            }
            if (binary_search(a.begin(), a.end(), -(*i + *j)))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << findTriplets(a, n) << "\n";
    }
}