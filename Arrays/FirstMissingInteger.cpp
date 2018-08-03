/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

LINK: https://www.interviewbit.com/problems/first-missing-integer/
*/

int Solution::firstMissingPositive(vector<int> &A) 
{
    int n = A.size();
    
    int j=0;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]<=0)
        {
            swap(A[i],A[j]);
            j++;
        }
    }
    
    int size=n-j;
    
    for(int i=j;i<n;i++)
    {
        if(abs(A[i])-1+j < n && A[abs(A[i])-1+j]>0)
            A[abs(A[i])-1+j] = -A[abs(A[i])-1+j];
    }
    
    for(int i=j;i<n;i++)
        if(A[i]>0)
            return (i-j+1);
    
    return (n-j+1);
}