/*
Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]
Output:

1
Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.

LINK: https://www.interviewbit.com/problems/minimize-the-absolute-difference/
*/

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    int res = INT_MAX;
    int i=0,j=0,k=0;
    int na=A.size(), nb=B.size(), nc=C.size();
 
    while(i<na && j<nb && k<nc)
    {
        int mn = min(A[i],min(B[j],C[k]));
        int mx = max(A[i],max(B[j],C[k]));
 
        res = min(res, mx-mn);
 
        if(res==0)
            break;
 
        if(A[i]==mn)
            i++;
        else
        if(B[j]==mn)
            j++;
        else
            k++;
    }
    return res;
}