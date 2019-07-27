/*
tarting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each of the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in your array.

For example, the length of your array of zeros . Your list of queries is as follows:

    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of  between the indices  and  inclusive:

index->	 1 2 3  4  5 6 7 8 9 10
	[0,0,0, 0, 0,0,0,0,0, 0]
	[3,3,3, 3, 3,0,0,0,0, 0]
	[3,3,3,10,10,7,7,7,0, 0]
	[3,3,3,10,10,8,8,8,1, 0]
The largest value is  after all operations are performed.*/


#include<bits/stdc++.h>
using namespace std;




long int max_el(vector <int> a,vector <int> b, vector <int> k)
{
    vector <long int> x(*max_element(b.begin(),b.end())+1);
    
    for(int i=0;i<a.size();++i)
    {
        x[a.at(i)]+=k.at(i);
        x[b.at(i)+1]-=k.at(i);
    }

    
    long int max_val=INT_MIN, val=0;
    for(auto i=x.begin();i!=x.end();++i)
    {
        val+=*i;
        if(val>max_val)
            max_val=val;
    }
    return max_val;

}

int main()
{

    int m,temp,n;
    cin>>n>>m;
    vector <int> a,b,k;


    while(m--)
    {
        cin>>temp;
        a.push_back(temp-1);
        cin>>temp;
        b.push_back(temp-1);
        cin>>temp;
        k.push_back(temp);
    }
    cout<<max_el(a,b,k);
    return 0;
}