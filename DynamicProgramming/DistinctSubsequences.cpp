/*
Given two sequences S, T, count number of unique ways in sequence S, to form a subsequence that is identical to the sequence T.

 Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none ) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Example :

S = "rabbbit" 
T = "rabbit"
Return 3. And the formations as follows:

S1= "ra_bbit" 
S2= "rab_bit" 
S3="rabb_it"
"_" marks the removed character.

LINK: https://www.interviewbit.com/problems/distinct-subsequences/
*/

int Solution::numDistinct(string A, string B)
{
    int na = A.length();
    int nb = B.length();
    int dp[na+1][nb+1];
    memset(dp,0,sizeof(dp));
 
    for(int i=0;i<na;i++)
        dp[i][0] =  1;
 
    for(int i=1;i<=na;i++)
    {
        for(int j=1;j<=nb;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(A[i-1]==B[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[na][nb];
}