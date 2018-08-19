/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return 1 ( true ).

A = [3,2,1,0,4], return 0 ( false ).

Return 0/1 for this problem

LINK: https://www.interviewbit.com/problems/jump-game-array/
*/

int Solution::canJump(vector<int> &A)
{
    int n = A.size();
    int minIndexToReach = n-1;
 
    for(int i=n-2;i>=0;i--)
    {
        if(i+A[i] >= minIndexToReach)
            minIndexToReach = i;
    }
 
    if(minIndexToReach==0)
        return 1;
    return 0;
}