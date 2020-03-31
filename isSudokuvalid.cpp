#include <bits/stdc++.h>
using namespace std;

bool validateRows(vector<int> s)
{
    int x;
    for (int i = 0; i < 9; ++i)
    {
        unordered_set<int> t;
        for (int j = 0; j < 9; ++j)
        {
            x = s.at(i * 9 + j);
            if (!x)
                continue;
            if (t.find(x) == t.end())
            {
                t.insert(x);
            }
            else
            {
              
                return false;
            }
        }
    }
    return true;
}
bool validateCols(vector<int> s)
{
    int x;
    for (int i = 0; i < 9; ++i)
    {
        unordered_set<int> t;
        for (int j = 0; j < 9; ++j)
        {
            x = s.at(j * 9 + i);
            if (!x)
                continue;
            if (t.find(x) == t.end())
            {
                t.insert(x);
            }
            else
            {

                return false;
            }
        }
    }
    return true;
}
bool validateMatrix(vector<int> s)
{
    int x;
    int a[9]={0,3,6,27,30,33,54,57,60};
    for (int i = 0; i < 9; ++i)
    {
        unordered_set<int> t;
        for (int j = 0; j < 27; j = j + 9)
        {
            for (int k = 0; k < 3; ++k)
            {
                x = s.at(a[i]  + j + k);
                //cout << a[i] + j + k << " ";
                if (!x)
                    continue;
                if (t.find(x) == t.end())
                {
                    t.insert(x);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool validate(vector<int> s)
{
    return validateRows(s) && validateCols(s) && validateMatrix(s);
}

int main()
{
    int t, n, temp;
    cin >> t;
    while (t--)
    {

        vector<int> s;
        for (int i = 0; i < 81; ++i)
        {
            cin >> temp;
            s.push_back(temp);
        }

        cout << validate(s) << "\n";
    }
}