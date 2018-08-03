/*
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C.

LINK: https://www.interviewbit.com/problems/array-3-pointers/
*/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
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