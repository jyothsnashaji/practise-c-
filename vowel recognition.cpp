/*find the presence of vowels in all possible substrings of the given string. For each given string you have to print the total number of vowels.

 

Input

First line contains an integer T, denoting the number of test cases.

Each of the next lines contains a string, string contains both lower case and upper case .

Output

Print the vowel sum
Answer for each test case should be printed in a new line.

Input Constraints

1<=T<=10

1<=|S|<=100000*/



#include<iostream>
#include<string.h>
using namespace std;
long int c;
char s[100000];
long int y[100000];
long int fv(int i)
{ 
    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' )
        return 1;
    else return 0;
}
long int count(int i, int j)
{if(i==j)
    y[i]=fv(i);
 else
 if(fv(i)==0)
    y[i]=count(i+1,j);
       
  else
 y[i]=(j-i+1)+count(i+1,j);
 return y[i];
  }

int main()
 
{
    int t;
    long int c;
    cin>>t;
    while(t--)
    {
        cin>>s;
         long int l=strlen(s);
         c=count(0,l-1);
       
        for(long int i=1;i<l;++i)
           c=c+y[i];
        cout<<c<<"\n";
    }

}