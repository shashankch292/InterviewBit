/*
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.

LINK: https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
*/

int Solution::solve(vector<string> &A) 
{
    long double a,b,c;
    a = stold(A[0]);
    b = stold(A[1]);
    c = stold(A[2]);
    
    for(int i=3;i<A.size();i++)
    {
        if((a+b+c)>1 && (a+b+c)<2)
            return 1;
            
        //cout<<a<<" "<<b<<" "<<c<<"\n";
        
        if((a+b+c)>=2)
        {
            if(a>b && a>c)
                a=stold(A[i]);
            else
            if(b>a && b>c)
                b=stold(A[i]);
            else
                c=stold(A[i]);
        }
        else
        {
            if(a<b && a<c)
                a=stold(A[i]);
            else
            if(b<a && b<c)
                b=stold(A[i]);
            else
                c=stold(A[i]);
        }
    }
    
    if((a+b+c)>1 && (a+b+c)<2)
        return 1;
    
    return 0;
}