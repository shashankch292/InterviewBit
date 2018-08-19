/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1. Return 0/1 for this problem.

LINK: https://www.interviewbit.com/problems/scramble-string/
*/

int Solution::isScramble(const string A, const string B)
{
    int n = A.length();
    if(n != B.length())
        return 0;
 
    if(A==B)
        return 1;
 
    bool dp[n][n][n+1];
    memset(dp,false,sizeof(dp));
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j][0] = true;
            dp[i][j][1] = (A[i]==B[j]);
        }
    }
 
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            for(int j=0;j<=n-l;j++)
            {
                for(int k=1;k<=l;k++)
                {
                    if((dp[i][j][k] && dp[i+k][j+k][l-k]) || (dp[i][j+l-k][k] && dp[i+k][j][l-k]))
                    {
                        dp[i][j][l] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][0][n];
}