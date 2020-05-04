/*Given a matrix of size NxM where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.*/

#include <bits/stdc++.h>
using namespace std;
int n, m;

queue<pair<int, int>> bfs(int a[50][50], vector<vector<bool>> &visited, int i, int j)
{
    queue<pair<int, int>> q, res;
    int ni, nj;
    q.push(make_pair(i, j));
    pair<int, int> c;
    bool t = false;
    int sides[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    while (!q.empty())
        
    {
        c = q.front();
        q.pop();
        //cout<<c.first<<" "<<c.second<<"//";
        visited[c.first][c.second] = true;

        for (int k = 0; k < 4; ++k)
        {
            ni = c.first + sides[k][0];
            nj = c.second + sides[k][1];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m)
            {
                t = true;
            }
            else if (!a[ni][nj] && !visited[ni][nj])
                q.push(make_pair(ni, nj));
        }
        res.push(c);
    }
    if (t)
    {
        queue<pair<int, int>> e;
        return e;
    }
    else
        return res;
}

void replace(int a[50][50])
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!a[i][j] && !visited[i][j])
            {
                q = bfs(a, visited, i, j);
                
                while (!q.empty())
                {
                    a[q.front().first][q.front().second] = 1;
                    q.pop();
                }
            }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            if (a[i][j])
                cout << 'X';
            else
                cout << 'O';
      
    }
      cout << "\n";
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        char c;
        cin >> n >> m;
        int a[50][50];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                cin >> c;
                a[i][j] = c == 'X' ? 1 : 0;
            }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                if (a[i][j])
                    cout << 'X';
                else
                    cout << 'O';
            cout << "\n";
        }
        replace(a);
    }
    return 0;
}