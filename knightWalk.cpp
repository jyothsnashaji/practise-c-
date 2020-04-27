/*Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). The task to find minimum number of moves required by the Knight to go to the destination cell.

Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. Each test case contains two lines. The first line of each testcase contains two space separated integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.

Output:
For each testcase in a new line print the minimum number of moves required by the knight to go to the destination from the source. If no such move is possible print -1.*/

#include <bits/stdc++.h>
using namespace std;

int n, m, d1, d2;

int bfs(int s1, int s2)
{
    int cs1, cs2, minv = INT16_MAX;
    vector<vector<int>> v(n+1, vector<int>(m+1, INT16_MAX));
    queue<pair<int, int>> q;
    int a[8][2] = {{1, 2}, {1, -2},{-1,2},{-1,-2} ,{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    pair<int, int> c;
    v[s1][s2]=0;
    q.push(make_pair(s1, s2));
    while (!q.empty())
    {
        c = q.front();
        q.pop();
       // cout<<c.first<<" "<<c.second<<" "<<v[c.first][c.second]<<".."<<minv<<"//";
        if (c.first == d1 && c.second == d2)
         return v[c.first][c.second];
        for (int i = 0; i < 8; ++i)
        {
            cs1 = c.first + a[i][0];
            cs2 = c.second + a[i][1];
            if (cs1 > 0 && cs2 > 0 &&  cs1 <= n && cs2 <= m && v[cs1][cs2] > v [c.first][c.second] + 1)
            {  // cout<<cs1<<" "<<cs2<<"//";
                q.push(make_pair(cs1, cs2));
                v[cs1][cs2] = v[c.first][c.second] + 1;
            }
        }
    }
    
   
    return  -1;
}


int dfs(int s1, int s2)
{
    int cs1, cs2, minv = INT16_MAX;
    vector<vector<int>> v(n+1, vector<int>(m+1, INT16_MAX));
    stack<pair<int, int>> s;
    int a[8][2] = {{1, 2}, {1, -2},{-1,2},{-1,-2} ,{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    pair<int, int> c;
    v[s1][s2]=0;
    s.push(make_pair(s1, s2));
    while (!s.empty())
    {
        c = s.top();
        s.pop();
       // cout<<c.first<<" "<<c.second<<" "<<v[c.first][c.second]<<".."<<minv<<"//";
        if (c.first == d1 && c.second == d2)
            minv = min(minv, v[c.first][c.second]);
        for (int i = 0; i < 8; ++i)
        {
            cs1 = c.first + a[i][0];
            cs2 = c.second + a[i][1];
            if (cs1 > 0 && cs2 > 0 &&  cs1 <= n && cs2 <= m && v[cs1][cs2] > v [c.first][c.second] + 1)
            {  // cout<<cs1<<" "<<cs2<<"//";
                s.push(make_pair(cs1, cs2));
                v[cs1][cs2] = v[c.first][c.second] + 1;
            }
        }
    }
    
    if(minv==INT16_MAX)
    minv=-1;
    return  minv;
}

int main()
{
    int t, s1, s2;

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> s1 >> s2 >> d1 >> d2;
        bool v[25][25];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                v[i][j] = false;
        //cout << dfs(s1, s2) << "\n";
        cout << bfs(s1, s2) << "\n";

    }
    return 0;
}