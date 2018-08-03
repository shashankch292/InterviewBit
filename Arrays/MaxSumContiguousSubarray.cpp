/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

LINK: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
*/

int Solution::maxSubArray(const vector<int> &A) 
{
    int mx = INT_MIN, mxt = 0;
    
    for(int i=0;i<A.size();i++)
    {
        mxt += A[i];
        mx = max(mx,mxt);
        if(mxt<0)
            mxt = 0;
    }
    return mx;
}