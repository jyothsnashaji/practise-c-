/*You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.
 

Input :
The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

Output :
Print in a new line the two numbers in ascending order.*/

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cout << *i << " ";
    }
}

void duplicate(vector<int> a)
{
    sort(a.begin(), a.end());

    int c = 1, count = 0;
    auto i = a.begin();
    while (++i != a.end())
    {
        
        if (*i == *(i - 1))
        {
            ++c;
        }
        else
        {
            if (c % 2)
            {
                cout << *(i - 1)<<" ";
                ++count;
                if (count == 2)
                {
                    cout << "\n";
                    return;
                }
            }
            c = 1;
        }
       
    }
    if (c%2)
    {
        cout << *(i - 1) << "\n";
       
    }
}

int main()
{
    int t, n, temp;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a;
        for (int i = 0; i < 2 * n + 2; ++i)
        {
            cin >> temp;
            a.push_back(temp);
        }
        duplicate(a);
    }

    return 0;
}