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