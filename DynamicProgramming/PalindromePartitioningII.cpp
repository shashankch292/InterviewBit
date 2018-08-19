/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example : 
Given 
s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

LINK: https://www.interviewbit.com/problems/palindrome-partitioning-ii/
*/

int Solution::minCut(string A)
{
    int n = A.length();
 
    if(n==0)
        return 0;
 
    int dp[n];
    bool palin[n][n];
 
    for(int i=0;i<n;i++)
        palin[i][i] = true;
 
    for(int len = 2;len<=n;len++)
    {
        for(int i=0;i<n-len+1;i++)
        {
            int j = i+len-1;
 
            if(len == 2)
                palin[i][j] = (A[i]==A[j]);
            else
                palin[i][j] = (A[i]==A[j]) && palin[i+1][j-1];
        }
    }
 
    for(int i=0;i<n;i++)
    {
        if(palin[0][i])
            dp[i] = 0;
        else
        {
            dp[i] = INT_MAX;
            for(int j=1;j<=i;j++)
                if(palin[j][i] && dp[i]>(dp[j-1]+1))
                    dp[i] = dp[j-1] + 1;
        }
    }
    return dp[n-1];
}