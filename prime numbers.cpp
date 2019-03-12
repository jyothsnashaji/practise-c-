/*
Prime Numbers between a range(a,b) whose sum of digits are also prime*/

#include<iostream>
#include<string.h>

using namespace std;

long int givec(long int a)
{   if(!a)
        return 0;
    else
        return a%10+givec(a/10);
}
int m[1000000];
int isprime(long int a)
{if(m[a]==1)
    return 1;
else if (m[a]==-1)
    return 0;
else
   { if(a%2==0)
        if(a!=2)
            {m[a]= -1;
            return 0;}
        else
           { m[a]= 1;
           return 1;}
    else
        {long int i=3;
         while(i*i<=a)
            {if(a%i==0)
                {m[a]= -1;
                 return 0;
                }
            
            while(isprime(++i)!=1);
            
            }
        m[a]= 1;
        return 1;
        }
   }

}
int main()
{
    long int a,b,c;
 
    cin>>a;
    cin>>b;
    if (a%2==0)
        a=a+1;
        
    while(a<=b)
    {if(isprime(a)&&isprime(givec(a)))
        cout<<a<<" ";
    a=a+2;
    }
}