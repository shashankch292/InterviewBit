/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example,
Given:

s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/interleaving-strings/
*/

int Solution::isInterleave(string A, string B, string C)
{
    int na = A.length();
    int nb = B.length();
 
    if(na+nb != C.length())
        return 0;
 
    int dp[nb+1];
    memset(dp,0,sizeof(dp));
 
    for(int i=0;i<=na;i++)
    {
        for(int j=0;j<=nb;j++)
        {
            if(i==0 && j==0)
                dp[j] = 1;
            else
            if(i==0)
                dp[j] = dp[j-1] && B[j-1]==C[i+j-1];
            else
            if(j==0)
                dp[j] = dp[j] && A[i-1]==C[i+j-1];
            else
            {
                dp[j] = (dp[j] && A[i-1]==C[i+j-1]) || (dp[j-1] && B[j-1]==C[i+j-1]);
            }
        }
    }
    return dp[nb];
}