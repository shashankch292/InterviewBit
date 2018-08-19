/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path

RIGHT-> RIGHT -> DOWN -> DOWN.

Dungeon Princess: Example 1



Input arguments to function:
Your function will get an M*N matrix (2-D array) as input which represents the 2D grid as described in the question. Your function should return an integer corresponding to the knight’s minimum initial health required. 



 Note:
The knight’s health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.


LINK: https://www.interviewbit.com/problems/dungeon-princess/
*/

int Solution::calculateMinimumHP(vector<vector<int> > &A)
{
    int m = A.size();
    int n = A[0].size();
 
    int dp[m][n];
    memset(dp,0,sizeof(dp));
 
    dp[m-1][n-1] = (A[m-1][n-1] > 0) ? 1 : abs(A[m-1][n-1])+1;
 
    for(int i=m-2;i>=0;i--)
        dp[i][n-1] = max(dp[i+1][n-1] - A[i][n-1], 1);
    for(int i=n-2;i>=0;i--)
        dp[m-1][i] = max(dp[m-1][i+1] - A[m-1][i], 1);
 
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            int val = min(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = max(val - A[i][j], 1);
        }
    }
 
    return dp[0][0];
}