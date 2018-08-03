/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

LINK: https://www.interviewbit.com/problems/3-sum/
*/

int Solution::threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int n = A.size();
 
    int res = A[n-1]+A[n-2]+A[n-3];
 
    for(int i=0;i<n-2;i++)
    {
        int l=i+1, r=n-1;
 
        while(l<r)
        {
            int sum = A[i]+A[l]+A[r];
            if(sum == B)
                return B;
 
            if(abs(sum-B)<abs(res-B))
                res = sum;
 
            if(sum<B)
                l++;
            else
                r--;
        }
    }
    return res;
}