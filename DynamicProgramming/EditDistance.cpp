/*
Given two words A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example : 
edit distance between
"Anshuman" and "Antihuman" is 2.

Operation 1: Replace s with t.
Operation 2: Insert i.

LINK: https://www.interviewbit.com/problems/edit-distance/
*/

int Solution::minDistance(string A, string B)
{
    int na = A.length(), nb = B.length();
 
    int dp[na+1][nb+1];
 
    for(int i=0;i<=na;i++)
        dp[i][0] = i;
    for(int j=0;j<=nb;j++)
        dp[0][j] = j;
 
    for(int i=1;i<=na;i++)
    {
        for(int j=1;j<=nb;j++)
        {
            if(A[i-1]==B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[na][nb];
}