/*Imagine you have a collection of N wines placed next to each other on a shelf. 
For simplicity, let's number the wines from left to right as they are standing on the shelf 
with integers from 1 to N, respectively. The price of the ith wine is pi. (prices of 
different wines can be different).Because the wines get better every year, 
supposing today is the year 1, on year y the price of the ith wine will be y*pi, 
i.e. y-times the value that current year.You want to sell all the wines you have,
but you want to sell exactly one wine per year, starting on this year. One more 
constraint - on each year you are allowed to sell only either the leftmost or the rightmost
 wine on the shelf and you are not allowed to reorder the wines on the shelf (i.e. they must 
 stay in the same order as they are in the beginning).
What is the maximum profit you can get, if you sell the wines in optimal order?*/


#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int a[100],n;

int profit(int p, int q)
{
    if(p>q )

    {
        return 0;
    }
    int y;
    if (p==q)
        y=n;
    else
        y=n-(q-p);
    return max(a[p]*y+profit(p+1,q),a[q]*y+profit(p,q-1));
}

int main()
{
    
    cout<<"n: ";
    cin>>n;
    int i;
    cout<<"Prices: ";
    for(i=0;i<n;++i)
    {
        cin>>a[i];

    }
    int p[n][n];
    cout<<profit(0,n-1);
    return 0;
}