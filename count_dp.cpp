/*Soumika has a string S and its starting index is 1. The string S consists of characters from . As she is very intelligent, she wants to test his brother Vinay Tendulkar. She asked her brother Vinay Tendulkar to count the number of even numbered characters ( i.e  ) for every index i . For an index i, the result should be calculated from i to the end of the string. As Vinay doesn't know about programming, he wants you to help him find the solution.

Input:
First line contains a string S.

Output:
Print |S| space-separated integers,the result of every index.

Constraints:
1 ≤ |S| ≤ 10^4 */

#include<iostream>
#include<string.h>

using namespace std;

int ans[10000];
void count(char str [],int i)

{
    if(i<0)
        return ;
    else
    {
        if (str[i]%2==0)
            ans[i]=ans[i+1]+1;
        else
        {
            ans[i]=ans[i+1];
        }
        
        count(str,i-1);
    }
    




}

int main()
{
    char str[100000];
    cin>>str;
    ans[strlen(str)]=0;
    count(str,strlen(str)-1);
    for(int i=0;i<strlen(str);++i)
        cout<<ans[i]<<" ";

    return 0;
}