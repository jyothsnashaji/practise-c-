/* Two friends Kunal and Satyam are playing an interesting game. They take turns drawing a ball from a bag which initially contains R red balls and G green balls. Each player draws a ball alternatively and never put it back. The person who is the first to draw a red balls wins. Satyam always draws first. If there are no more balls in the bag and nobody has drawn a red ball, the satyam wins.

What is the probability of the Satyam winning?
Input:
The first line will contain the number of test cases T.
The first line of each test case will contain a number R (number of red balls) and G(number of green balls )

Output 
For each testcase, print the desired probability.
Constraints:
1<=T<=10
0<=R,G<=10^3 */



#include<iostream>
#include<iomanip>

using namespace std;
double r,g;
double p[1000];
double  prop(int i)
{
    if(r==0||i>g||g<=(i-1)*2)
    {
        return 0;
    }
   
    else
    {
        p[i]=p[i-1]*(g-2*i+4)*(g-2*i+3)/(g+r-2*i+3)/(g+r-2*i+2);
        
        return p[i]+prop(i+1);
    }
    
    

}

int main()
{
    int t;
    
    cin>>t;
    while(t--)
    {
        cin>>r>>g;
        if(g==0 ||r==0)
           p[1]=1; 
        else
        {
            p[1]=r/(g+r);
            
        }
        
        cout<<fixed<<setprecision(6);
        cout<<(double)p[1]+prop(2)<<"\n";
        
        

    }

    return 0;
}