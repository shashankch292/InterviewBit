/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' : Matches any single character.
'*' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Examples :

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "*") → 1
isMatch("aa", "a*") → 1
isMatch("ab", "?*") → 1
isMatch("aab", "c*a*b") → 0
Return 1/0 for this problem.

LINK: https://www.interviewbit.com/problems/regular-expression-match/
*/

int Solution::isMatch(const string A, const string B)
{
    int na = A.length();
    int nb = B.length();
 
    if(nb==0)
        return (na==0);
 
    bool dp[nb+1];
    memset(dp,false,sizeof(dp));
 
    dp[0]=true;
 
    for(int i=1;i<=nb;i++)
        if(B[i-1]=='*')
            dp[i] = dp[i-1];
 
    bool temp;
 
    for(int i=1;i<=na;i++)
    {
        temp = dp[0];
        for(int j=1;j<=nb;j++)
        {
            bool match = false;
            if(B[j-1]=='?' || A[i-1]==B[j-1])
                match = temp;
            else
            if(B[j-1]=='*')
                match = dp[j] || dp[j-1];
 
            temp = dp[j];
            dp[j] = match;
        }
        dp[0]=false;
    }
    return dp[nb];
}