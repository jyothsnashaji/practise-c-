/*Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.*/

vector<int> Solution::plusOne(vector<int> &A) 
{
    auto i=A.end()-1;
    
    while(1)
    {
        
        *i=*i+1;
        if(*i==10)
        {
           *i=0; 
           if(i==A.begin())
           {
               A.insert(i,1);
               break;
           }
        }
        else
        {
            break;
        }
    if(i!=A.begin())
        --i;
    else
        break;
    }
    while(find(A.begin(),A.end(),0)==A.begin())
    {
        A.erase(A.begin());
    }
    return A;
}
