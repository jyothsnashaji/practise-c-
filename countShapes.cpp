/*Given N * M string array of O's and X's. The task is to find the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's (diagonals not included).

Input: The first line of input takes the number of test cases T. Then T test cases follow. Each of the T test cases takes 2 input lines. The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:
For each testcase, print number of shapes.

Constraints:
1 <= T <= 100
1 <= N, M <= 50

Example:
Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6*/
#include <bits/stdc++.h>
using namespace std;

void markVisited(int a[][50], int n, int m, vector<vector<bool>> &isVisited, int row, int col)
{
    isVisited[row][col] = true;
    if (col && a[row][col - 1] && !isVisited[row][col - 1])
    {
        markVisited(a, n, m, isVisited, row, col - 1);
    }
    if (row && a[row - 1][col] && !isVisited[row - 1][col])
    {
        markVisited(a, n, m, isVisited, row - 1, col);
    }
    if (col < m-1 && a[row][col + 1] && !isVisited[row][col + 1])
    {
        markVisited(a, n, m, isVisited, row, col + 1);
    }

    if (row < n-1 && a[row + 1][col] && !isVisited[row+1][col])
    {
        markVisited(a, n, m, isVisited, row + 1, col);
    }
}

int countShapes(int a[][50], int n, int m)
{
    int c = 0;
    vector<vector<bool>> isVisited( n , vector<bool> (m, false));
  /*  for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << isVisited[i][j] << " ";
        }
        cout << "\n";
    }*/
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] && !isVisited[i][j])
            {
                ++c;
               // cout<<i<<" "<<j<<"..";
                markVisited(a, n, m, isVisited, i, j);
            }
        }
    }
    return c;
}

int main()
{
    int t, n, m;
    char temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int a[50][50];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> temp;
                if (temp == 'X')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }

      /*  for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }*/
        cout << countShapes(a, n, m)<<"\n";
    }
}