/*You are given a sequence of points and the order in which you need to cover the points.
Give the minimum number of steps in which you can achieve it. You start from the first point. 
Input :

Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
Output :

Return an Integer, i.e minimum number of steps.*/


int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int c=0;
    for(auto i=A.begin(),j=B.begin();i!=A.end()-1;++i,++j)
    {
        c=c+max(abs(*i-*(i+1)),abs(*j-*(j+1)));
            
    }
    return c;
    
}

