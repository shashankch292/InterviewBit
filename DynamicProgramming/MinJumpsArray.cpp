/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example :
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.

LINK: https://www.interviewbit.com/problems/min-jumps-array/
*/

int Solution::jump(vector<int> &A)
{
    int n = A.size();
 
    if(n<=1)
        return 0;
    if(A[0]==0)
        return -1;
 
    int maxInd = A[0];
    int stepsLeft = A[0];
    int jumps = 1;
 
    for(int i=1;i<n-1;i++)
    {
        maxInd = max(maxInd, i+A[i]);
        stepsLeft--;
 
        if(stepsLeft == 0)
        {
            jumps++;
 
            if(i>=maxInd)
                return -1;
            stepsLeft = maxInd-i;
        }
    }
    return jumps;
}