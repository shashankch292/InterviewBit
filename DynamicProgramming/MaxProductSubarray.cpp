/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]

LINK: https://www.interviewbit.com/problems/max-product-subarray/
*/

int Solution::maxProduct(const vector<int> &A)
{
    int n = A.size();
    if(n==0)
        return 0;
 
    int curMax, curMin, preMax, preMin, ans;
    ans = preMax = preMin = A[0];
 
    for(int i=1;i<n;i++)
    {
        curMax = max(A[i], max(A[i]*preMax, A[i]*preMin));
        curMin = min(A[i], min(A[i]*preMax, A[i]*preMin));
 
        ans = max(ans, curMax);
 
        preMax = curMax;
        preMin = curMin;
    }
    return ans;
}