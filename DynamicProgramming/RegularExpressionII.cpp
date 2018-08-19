/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

LINK: https://www.interviewbit.com/problems/regular-expression-ii/
*/

int Solution::isMatch(const string A, const string B)
{
    int na = A.length();
    int nb = B.length();
 
    bool dp[na+1][nb+1];
    memset(dp,false,sizeof(dp));
 
    dp[na][nb] = true;
 
    for(int i=na;i>=0;i--)
    {
        for(int j=nb-1;j>=0;j--)
        {
            bool match = (i<na && (A[i]==B[j] || B[j]=='.'));
 
            if(j+1<nb && B[j+1]=='*')
                dp[i][j] = dp[i][j+2] || (match && dp[i+1][j]);
            else
                dp[i][j] = match && dp[i+1][j+1];
        }
    }
    return dp[0][0];
}