/*Given an array of integers, find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.*/

#include <bits/stdc++.h>
using namespace std;

int maxDiff(vector<int> a)
{
    int max_ = INT16_MIN, n = a.size();
    vector<int> maxLeft(n);
    vector<int> maxRight(n);
    vector<int> minLeft(n);
    vector<int> minRight(n);

    int max_ending_here = 0;
    int max_so_far = INT16_MIN;

    for (int i = 0; i < n; ++i)
    {
        max_ending_here = max(a[i], max_ending_here + a[i]);
        max_so_far = max(max_so_far, max_ending_here);
        maxLeft[i] = max_so_far;
    }
    max_ending_here = 0;
    max_so_far = INT16_MIN;
    for (int i = n - 1; i >= 0; --i)
    {
        max_ending_here = max(a[i], max_ending_here + a[i]);
        max_so_far = max(max_so_far, max_ending_here);
        maxRight[i] = max_so_far;
    }

    int min_ending_here = 0;
    int min_so_far = INT16_MAX;

    for (int i = 0; i < n; ++i)
    {
        min_ending_here = min(a[i], min_ending_here + a[i]);
        min_so_far = min(min_so_far, min_ending_here);
        minLeft[i] = min_so_far;
    }
    min_ending_here = 0;
    min_so_far = INT16_MAX;
    for (int i = n - 1; i >= 0; --i)
    {
        min_ending_here = min(a[i], min_ending_here + a[i]);
        min_so_far = min(min_so_far, min_ending_here);
        minRight[i] = min_so_far;
    }

    for (int i = 0; i < n; ++i)
        max_ = max(max_, max(abs(maxLeft[i] - minRight[i]), abs(maxRight[i] - minLeft[i])));

    return max_;
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
        cout << maxDiff(a) << "\n";
    }
    return 0;
}