/*You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.
 */

#include <bits/stdc++.h>
using namespace std;

void pairs(vector<int> a)
{
    unordered_map<int, int> h;
    vector<int> ans;
    for (int i = 0; i < a.size(); ++i)
        h[a[i]]++;

    for (auto i = h.begin(); i != h.end() && ans.size() < 2; ++i)
        if (i->second % 2)
           {
ans.push_back(i->first);
//cout<<i->first<<" "<<i->second<<"//";
           } 

    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << ans[1];
}

int main()
{
    int t, n, p;

    cin >> t;
    while (t--)
    {
        cin >> n;
        n=2*n+2;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        //cout << dfs(s1, s2) << "\n";
      pairs(a);
      cout << "\n";
    }
    return 0;
}