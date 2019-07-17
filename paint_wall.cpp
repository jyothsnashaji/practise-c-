/*Problem
Thanh wants to paint a wonderful mural on a wall that is N sections long. Each section of the wall has a beauty score, which indicates how beautiful it will look if it is painted. Unfortunately, the wall is starting to crumble due to a recent flood, so he will need to work fast!

At the beginning of each day, Thanh will paint one of the sections of the wall. On the first day, he is free to paint any section he likes. On each subsequent day, he must paint a new section that is next to a section he has already painted, since he does not want to split up the mural.

At the end of each day, one section of the wall will be destroyed. It is always a section of wall that is adjacent to only one other section and is unpainted (Thanh is using a waterproof paint, so painted sections can't be destroyed).

The total beauty of Thanh's mural will be equal to the sum of the beauty scores of the sections he has painted. Thanh would like to guarantee that, no matter how the wall is destroyed, he can still achieve a total beauty of at least B. What's the maximum value of B for which he can make this guarantee?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing an integer N. Then, another line follows containing a string of N digits from 0 to 9. The i-th digit represents the beauty score of the i-th section of the wall.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum beauty score that Thanh can guarantee that he can achieve, as described above.

Limits
1 ≤ T ≤ 100.
Time limit: 20 seconds per test set.
Memory limit: 1 GB.

Small dataset (Test set 1 - Visible)
2 ≤ N ≤ 100.

Large dataset (Test set 2 - Hidden)
For exactly 1 case, N = 5 × 106; for the other T - 1 cases, 2 ≤ N ≤ 100.

Sample

Input 
 	
Output 
 
4
4
1332
4
9583
3
616
10
1029384756

  
Case #1: 6
Case #2: 14
Case #3: 7
Case #4: 31
*/



#include<bits/stdc++.h>
using namespace std;

int compute_score(float n)
{
    vector <int> s;
    int temp;
    getchar();
    for(int i=0;i<n;++i)
    {
       
        temp=int(getchar()-48);
        s.push_back(temp);
    }
    int score=INT_MIN;
    int prev=0,size=ceil(n/2),sum=accumulate(s.begin(),s.begin()+size-1,0);
    for(auto i=s.begin();i+size-1!=s.end();++i)
    {
        sum=sum+*(i+size-1)-prev;
      //  cout<<*i<<" "<<sum<<" "<<prev<<"\n";
        prev=*i;  
        score=max(score,sum);
        
    }
    return score;

}
int main()
{
    int t,i=1;
    int ans;
    float n;
    cin>>t;
    while(i<=t)
    {
        cin>>n;
        ans=compute_score(n);
        cout<<"Case #"<<i++<<": "<<ans<<"\n";
    }

    return 0;
}