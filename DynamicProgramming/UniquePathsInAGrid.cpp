/*
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

 Note: m and n will be at most 100. 

LINK: https://www.interviewbit.com/problems/unique-paths-in-a-grid/
*/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A)
{
    int m = A.size();
    int n = A[0].size();
 
    int dp[m][n];
    memset(dp,0,sizeof(dp));
 
    if(A[0][0]==0)
        dp[0][0] = 1;
 
    for(int i=1;i<m;i++)
        dp[i][0] = A[i][0] ? 0 : dp[i-1][0];
    for(int i=1;i<n;i++)
        dp[0][i] = A[0][i] ? 0 : dp[0][i-1];
 
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(A[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
 
    return dp[m-1][n-1];
}