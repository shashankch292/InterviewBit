/*
Given a binary grid i.e. a 2D grid only consisting of 0’s and 1’s, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them. You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid. Please follow the below example for more clarity.

Lets say we are given a binary grid of 3 * 3 size.

1 0 1

0 1 0

1 0 0

At present we can see that max rectangle satisfying the criteria mentioned in the problem is of 1 * 1 = 1 area i.e either of the 4 cells which contain 1 in it. Now since we are allowed to permutate the columns of the given matrix, we can take column 1 and column 3 and make them neighbours. One of the possible configuration of the grid can be:

1 1 0

0 0 1

1 0 0

Now In this grid, first column is column 1, second column is column 3 and third column is column 2 from the original given grid. Now, we can see that if we calculate the max area rectangle, we get max area as 1 * 2 = 2 which is bigger than the earlier case. Hence 2 will be the answer in this case.

LINK: https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
*/

int Solution::solve(vector<vector<int> > &A)
{
    int r = A.size();
    int c = A[0].size();
 
    int dp[r][c];
 
    for(int j=0;j<c;j++)
    {
        dp[0][j] = A[0][j];
 
        for(int i=1;i<r;i++)
            dp[i][j] = (A[i][j]==0) ? 0 : dp[i-1][j]+1;
    }
 
    for(int i=0;i<r;i++)
    {
        int cnt[r+1];
        memset(cnt,0,sizeof(cnt));
 
        for(int j=0;j<c;j++)
            cnt[dp[i][j]]++;
 
        int col=0;
 
        for(int k=r;k>=0;k--)
        {
            if(cnt[k]>0)
            {
                while(cnt[k])
                {
                    dp[i][col++] = k;
                    cnt[k]--;
                }
            }
        }
    }
 
    int ans = 0;
 
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            ans = max(ans, (dp[i][j]*(j+1)));
 
    return ans;
}