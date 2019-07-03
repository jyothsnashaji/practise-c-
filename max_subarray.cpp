/*Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index */


#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

vector <int> Solution_maxset(vector<int> &A) 
{ long int max_sum = INT32_MIN,sum=INT32_MIN;
 vector <int>::iterator i,max_end=A.end(),bg=A.end(),max_bg=A.end();
   for( i=A.begin();i!=A.end();++i)
   {    //cout<<"\nnum"<<*i;
       if (*i>=0)
       {
           if(bg==A.end())
           {
               bg=i;
               sum=0;
               
           }

           sum=sum+*i;
       }
       else
       {
           if(sum>max_sum || (sum==max_sum && max_end!=A.end() && (max_end-max_bg)<(i-1-bg) ) )
           {   //cout<<"\nsums"<<sum<<" "<<max_sum;
               //cout<<"\n diff"<<(max_end-max_bg)<<"  "<<(i-1-bg);
               max_sum=sum;
               max_bg=bg;
               max_end=i-1;
               //cout<<"\n"<<*max_bg<<" "<<*max_end;
           }
           
           bg=A.end();
       }
       
   }
   if(sum>max_sum || (sum==max_sum && max_end!=A.end() && (max_end-max_bg)<(i-1-bg) ) )
           {
               max_sum=sum;
               max_bg=bg;
               max_end=i-1;
           }
   vector <int> res;
   if(max_bg!=A.end())
    copy(max_bg,max_end+1,back_inserter(res));
    //cout<<"\n"<<*max_bg<<" "<<*max_end;
   return res;
}

int main()
{
    vector <int> a;
    int n,temp;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>temp;
        a.push_back(temp);
    }
    a=Solution_maxset(a);

    for (int i=0;i<a.size();++i)
    {
        cout<<a.at(i)<<" ";
    
    }
    return 0;
}