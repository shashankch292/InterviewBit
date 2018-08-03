/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1
Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.

LINK: https://www.interviewbit.com/problems/set-matrix-zeros/
*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m=A.size();
    int n=A[0].size();
 
    int r[m],c[n];
 
    for(int i=0;i<m;i++)
        r[i]=0;
    for(int i=0;i<n;i++)
        c[i]=0;
 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==0)
            {
                r[i]=1;
                c[j]=1;
            }
        }
    }
 
    for(int i=0;i<m;i++)
    {
        if(r[i]==1)
        {
            for(int j=0;j<n;j++)
                A[i][j]=0;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(c[j]==1)
        {
            for(int i=0;i<m;i++)
                A[i][j]=0;
        }
    }
}