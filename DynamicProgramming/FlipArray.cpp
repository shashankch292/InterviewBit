/*
Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

Constraints:

 1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

 Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum 

LINK: https://www.interviewbit.com/problems/flip-array/
*/

int Solution::solve(const vector<int> &A)
{
    int n = A.size();
 
    if(n==0 || n==1)
        return 0;
 
    if(n==2)
        return 1;
 
    int sum = 0;
 
    for(int i=0;i<n;i++)
        sum += A[i];
 
    sum /= 2;
 
    long long int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
 
    for(int i=1;i<=sum;i++)
        dp[0][i] = INT_MAX;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=A[i-1])
                dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-A[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
 
    return dp[n][sum];
}