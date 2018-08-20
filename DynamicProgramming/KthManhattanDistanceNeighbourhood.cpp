/*
Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix. 
In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

Note: Expected time complexity is O(N*N*K)

Constraints:

1 <= n <= 300
1 <= m <= 300
1 <= K <= 300
0 <= M[i][j] <= 1000
Example:

Input:
M  = [[1,2,4],[4,5,8]] , K = 2

Output:
ans = [[5,8,8],[8,8,8]]

LINK: https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/
*/

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B)
{
    int n = B.size();
    int m = B[0].size();
 
    vector<vector<int> > res(n, vector<int>(m));
 
    int dp[2][n][m];
    memset(dp, -1, sizeof(dp));
 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[0][i][j] = B[i][j];
 
    int ko = 0;
    int kn = 1;
 
    for(int k=1;k<=A;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int val = dp[ko][i][j];
 
                if(i>0)
                    val = max(val, dp[ko][i-1][j]);
                if(j>0)
                    val = max(val, dp[ko][i][j-1]);
                if(i<n-1)
                    val = max(val, dp[ko][i+1][j]);
                if(j<m-1)
                    val = max(val, dp[ko][i][j+1]);
 
                dp[kn][i][j] = val;
            }
        }
        ko = (ko+1)%2;
        kn = (kn+1)%2;
    }
 
    A = A%2;
 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            res[i][j] = dp[A][i][j];
 
    return res;
}