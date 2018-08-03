/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

LINK: https://www.interviewbit.com/problems/add-one-to-number/
*/

vector<int> Solution::plusOne(vector<int> &A) 
{
    int c=1;
    
    for(int i=A.size()-1;i>=0;i--)
    {
        int num = A[i]+c;
        c = num/10;
        A[i] = num%10;
    }
    
    vector<int> v;
    if(c==1)
    {
        v.push_back(1);
        for(int i=0;i<A.size();i++)
            v.push_back(A[i]);
    }
    else
    {
        int i=0;
        while(i<A.size())
        {
            if(A[i]==0)
                i++;
            else
                break;
        }
        for(;i<A.size();i++)
            v.push_back(A[i]);
    }
    return v;
}
