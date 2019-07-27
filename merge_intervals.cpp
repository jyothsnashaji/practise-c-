/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

*/
#include <bits/stdc++.h>
using namespace std;




struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };

void print_vector(vector<Interval> a)
{
    struct Interval temp;
    for(auto i=a.begin();i!=a.end();++i)
    {
        temp=*i;
        cout<<"["<<temp.start<<","<<temp.end<<"] ";
    }
}
 
vector<Interval> insert1(vector<Interval> &intervals, Interval newInterval) 
{
    struct Interval temp,next;
    for(auto i=intervals.begin();i!=intervals.end();++i)
    {
        temp=*i;
        
        if(newInterval.start<temp.start)
        {
            auto prev=i;
            while(i!=intervals.end())
                {
                     temp=*i;
        
                    if(newInterval.end<temp.start)
                        {
                            intervals.insert(prev,newInterval);
                            return intervals;
                        }

                    if(newInterval.end<=temp.end)
                    {
                        newInterval.end=temp.end;
                        intervals.erase(i);
                        intervals.insert(i,newInterval);
                        return intervals;
                    }
                    prev=i;
                    intervals.erase(i);
                    
                }
            break;
        
        }

        if(newInterval.start<=temp.end)
        {
            newInterval.start=temp.start;
            while(i!=intervals.end())
                {
                     
                    temp=*i;
                    //cout<<"here"<<newInterval.end<<" "<<temp.end;
                    if(newInterval.end<=temp.end)
                        {
                            //cout<<"here"<<newInterval.end;
                            newInterval.end=temp.end;
                            intervals.erase(i);
                            intervals.insert(i,newInterval);
                            
                            return intervals;
                        }
                   
                    if(newInterval.end<(*(i+1)).start)
                    {
                       
                        intervals.erase(i);
                        intervals.insert(i,newInterval);
                        return intervals;
                    }
                    if(newInterval.end==(*(i+1)).start)
                    {
                        newInterval.end=(*(i+1)).end;
                        intervals.erase(i);
                        intervals.erase(i);
                        intervals.insert(i,newInterval);
                        return intervals;
                    }
                    //cout<<"erase"<<(*i).end;
                    intervals.erase(i);
                    
                }
               
        break;
           
        }
    }
 intervals.push_back(newInterval);
return intervals;
}
bool overlap (struct Interval r1,struct Interval r2)
{
   return  max(r1.start,r2.start)<min(r1.end,r2.end);
}


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
    auto i=intervals.begin(), pre=intervals.end();
    
    for( i=intervals.begin();i!=intervals.end()&&newInterval.start>(*i).start ;++i);
    cout<<"stop"<<(*i).start;
    if(i!=intervals.begin()&&overlap(*(i-1),newInterval))
    {
        newInterval.start=min(newInterval.start,(*(i-1)).start);
        intervals.erase(i-1);
        
        //cout<<"afterp";
        //print_vector(intervals);
        --i;
    }
    //cout<<(*i).start;
    while(i!=intervals.end()&&overlap(*i,newInterval))
    {
        //cout<<"over"<<(*i).start;
        newInterval.start=min(newInterval.start,(*i).start);
        newInterval.end=max(newInterval.end,(*i).end);
        intervals.erase(i);
       //cout<<"after";
        //print_vector(intervals);
    }
   //cout<<(*i).start;
    intervals.insert(i,newInterval);


    return intervals;
}

int main()
{
    int n;
    cin>>n;
    struct Interval temp;
    vector <Interval> a;
    while(n--)
    {
       cin>>temp.start>>temp.end;
       a.push_back(temp);
    }
    int t;
    cin>>t;
    while(t--)
    {cin>>temp.start>>temp.end;
    print_vector(insert(a,temp));}
    //print_vector(a);

    return 0;
}