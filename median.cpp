/*Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.*/

#include <bits/stdc++.h>
using namespace std;

void showpq(priority_queue<long int, vector<long int>, greater<long int>> right, priority_queue<long int> left)
{

    while (!left.empty())
    {
        cout << " " << left.top();
        left.pop();
    }

    cout << '\n';
    while (!right.empty())
    {
        cout << " " << right.top();
        right.pop();
    }
    cout << '\n';
}
void medianOpt(long int n)
{
    long int x, med = 0;
    priority_queue<long int> left;
    priority_queue<long int, vector<long int>, greater<long int>> right;
    for (long int i = 0; i < n; ++i)
    {
        cin >> x;
        if (left.size() == right.size())
        {
            if (x < med)
            {
                left.push(x);
                med = left.top();
            }
            else
            {
                right.push(x);
                med = right.top();
            }
        }
        else if (left.size() > right.size())
        {
            if (x < med)
            {
                right.push(left.top());
                left.pop();
                left.push(x);
            }
            else
            {
                right.push(x);
            }
            med = (left.top() + right.top()) / 2;
        }
        else
        {
            if (x < med)
            {
                left.push(x);
            }
            else
            {
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            med = (left.top() + right.top()) / 2;
        }
        //showpq(right, left);
        cout << med << "\n";
    }
}

long int median(vector<long int> &a, long int x)
{
    if (!a.size())
    {
        a.push_back(x);
        return x;
    }
    int i = 0, n = a.size();
    while (i < n && a[i++] < x)
        ;
    //cout<<i<<"..";
    if (i == n && a[i - 1] < x)
        a.insert(a.begin() + i, x);
    else
        a.insert(a.begin() + i - 1, x);
    ++n;
    if (n % 2 == 0)
    {
        //cout << a[n / 2 - 1] << " " << a[n / 2]<<"//";
        return (a[n / 2 - 1] + a[n / 2]) / 2;
    }
    else
        return a[n / 2];
}

int main()
{

    long int t, n, x;

    cin >> n;
    medianOpt(n);
    return 0;
}