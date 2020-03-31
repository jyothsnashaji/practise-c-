/*Count of strings that can be formed using a, b and c under given constraints*/
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t, n, temp;
    cin >> t;
    while (t--)
    {
        cin>>n;
        cout.setf(ios::fixed);
cout << setprecision(0) <<(pow(n,3)+3*n+2)/2<<"\n";
    }
}