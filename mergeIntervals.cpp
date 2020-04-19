/*Given a collection of Intervals,merge all the overlapping Intervals.
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector < pair <int,int>> intervals)
{
    int i=0;
    sort(intervals.begin(),intervals.end());
    while(i<intervals.size()-1)
    {
        if(intervals[i+1].first<=intervals[i].second)
        {
            intervals[i].second=max(intervals[i].second,intervals[i+1].second);
            intervals.erase(intervals.begin()+i+1);
        }
        else
        {
            ++i;
        }
    }
    for(int i=0;i<intervals.size();++i)
        cout<<intervals[i].first<<" "<<intervals[i].second<<" ";
    cout<<"\n";
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n ;
        vector < pair <int,int>> intervals;
        int f,s;
        for (int i = 0; i < n; ++i)
            {
                cin>>f>>s;
                intervals.push_back(make_pair(f,s));
            }
      merge(intervals);
    }
}
