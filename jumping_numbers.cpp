/*Given a positive number X. Find all Jumping Numbers smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

Input:
The first line of the input contains T denoting the number of testcases. Each testcase contain a positive number X.

Output:
Output all the jumping numbers less than X in sorted order. Jump to example for better understanding.*/
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << " ";
    }
}

void bfs(int i, int n, vector<int> &a)
{
    queue<int> q;
    int ld, num;
    q.push(i);
    while (!q.empty())
    {
        num = q.front();
        q.pop();

        if (num < n)
        {
            a.push_back(num);
            ld = num % 10;
            if (ld == 0)
            {
                q.push(num * 10 + (ld + 1));
            }
            else if (ld == 9)
            {
                q.push(num * 10 + (ld - 1));
            }
            else
            {

                q.push(num * 10 + (ld - 1));
                q.push(num * 10 + (ld + 1));
            }
        }
    }
}

void jumping_numbers(int n)
{
    vector<int> a;
    cout << 0 << " ";
    for (int i = 1; i <= 9 && i <= n; ++i)
    {
        bfs(i, n, a);
    }
    sort(a.begin(), a.end());
    print_vector(a);
    cout << "\n";
}

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        jumping_numbers(n);
    }

    return 0;
}