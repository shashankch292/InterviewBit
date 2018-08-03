/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

LINK: https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long int s1=0,s2=0;
    for(long long int i=0;i<A.size();i++)
    {
        long long int num = A[i];
        s1 += (num - (i+1));
        s2 += (num*num - (i+1)*(i+1));
    }
    
    int a,b;
    
    a = (s1 + (s2/s1))/2;
    b = a - s1;
    vector<int> v = {a,b};
    
    return v;
}