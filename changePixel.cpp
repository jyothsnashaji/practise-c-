/*Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4*/



#include <bits/stdc++.h>
using namespace std;

void changePixel(vector<vector<int>> &a, int x, int y, int n, int m, int k)
{
    queue<pair<int, int>> q;
    int c = a[x][y];
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        a[x][y] = k;
        q.pop();
        if (x && a[x - 1][y] == c)
            q.push(make_pair(x - 1, y));
        if (y && a[x][y - 1] == c)
            q.push(make_pair(x, y - 1));
        if (x < n - 1 && a[x + 1][y] == c)
            q.push(make_pair(x + 1, y));
        if (y < m - 1 && a[x][y + 1] == c)
            q.push(make_pair(x, y + 1));
    }
}

int main()
{
    int t, n, m, x, y, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        cin >> x >> y >> k;
        /*  for (int i = 0; i < n; ++i)
           { for (int j = 0; j < m; ++j)
                cout << a[i][j] << " ";
            cout<<"\n";}*/
        changePixel(a, x, y, n, m, k);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << a[i][j] << " ";
        cout << "\n";
    }
}