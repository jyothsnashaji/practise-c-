/*Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010*/

#include <bits/stdc++.h>
using namespace std;

#include <stdio.h>
#include <bits/stdc++.h>

void get_subarray_1(vector<int> a, long int s) // brute force
{
    long int sum;
    for (int i = 0; i < a.size(); ++i)
    {
        sum = a[i];
        if (sum == s)
        {
            cout << i + 1 << " " << i + 1 << "\n";
            return;
        }
        for (int j = i + 1; j < a.size(); ++j)
        {
            sum = sum + a[j];
            //cout<<a[i]<<" "<<a[j]<<" "<<sum<<"\n";
            if (sum == s)
            {
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
            if (sum > s)
            {
                break;
            }
        }
    }
    cout << -1 << "\n";
}

void get_subarray(vector<int> a, long int s)
{
    int i = 0, j = 0, n = a.size(), sum = a[i];
    while (j < n)
    {

        //cout << a[i] << " " << a[j] << " " << sum << "\n";
        if (sum == s)
        {
            cout << i + 1 << " " << j + 1 << " "<<"\n";
            return;
        }
        if (sum < s|| i==j)
        {
            ++j;
            sum = sum + a[j];
        }
        if (sum > s)
        {
            sum = sum - a[i];
            ++i;
        }
    }
    cout << -1 << "\n";
}
int main()
{
    int t, n, temp;
    long int s;
    cin >> t;
    while (t--)
    {
        vector<int> a;

        cin >> n >> s;

        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            a.push_back(temp);
        }
        get_subarray(a, s);
    }
    return 0;
}