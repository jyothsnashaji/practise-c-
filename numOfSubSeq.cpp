/*Given two sequences A, B, find out number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Example :
A = "abcccdf"  B = "abccdf"

Return 3. And the formations as follows:

A1= "ab.ccdf"
A2= "abc.cdf"
A3="abcc.df"

"." is where character is removed.


Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is a string A of length less than 1000.
Second is a string B of length less than 100.

Exapmle:
Input:
2
abcccdf
abccdf
uwnny
uwnny

Output:
3
1*/
#include <bits/stdc++.h>
using namespace std;
string x, y;

int numofSubseq(int num[][101], int i, int j)
{
    //cout << i << " " << j << "..";
    if (j == y.size())
        return 1;
    if (i == x.size())
        return 0;
    if (num[i + 1][j] == -1)
        num[i + 1][j] = numofSubseq(num, i + 1, j);

    if (x[i] == y[j])
    {
        if (num[i + 1][j + 1] == -1)
            num[i + 1][j + 1] = numofSubseq(num, i + 1, j + 1);
        return num[i + 1][j + 1] + num[i + 1][j];
    }
    else
    {
        return num[i + 1][j];
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num[1001][101];
        cin >> x >> y;
        //memset(num, -1, sizeof(num[0][0]) * y.size() * x.size());
        for (int i = 0; i < x.size()+1; ++i)
        {
            for (int j = 0; j < y.size()+1; ++j)
                num[i][j] = -1;
        }
        cout << numofSubseq(num, 0, 0) << "\n";
      /*  for (int i = 0; i < x.size(); ++i)
        {
            for (int j = 0; j < y.size(); ++j)
                cout << num[i][j] << " ";
            cout << "\n";
        }*/
    }
}