


#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;
int n;

int profit(vector <int> a)
{
    if(a.empty()==true)

    {
        cout<<"tata";  
        return 0;
    }
    
    int y=n-a.size()+1;

    int m=-1;
    vector <int> temp;
    for(int i=0; i<n;++i)
    {   
        temp=a;
         
        temp.erase(temp.begin()+i); // i gets changed after erasing check out!!
        

        m= max(m,a.at(i)*y+profit(temp));

    }
    return m;

}

int main()
{
    vector <int> a;
    cout<<"n: ";
    cin>>n;
    int i,in;
    
    cout<<"Numbers: ";
    for(i=0;i<n;++i)
    {
        cin>>in;
        a.push_back(in);
    }
    int p[n][n];
    cout<<profit(a);
    return 0;
}