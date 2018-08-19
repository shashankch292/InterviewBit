/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Example :

Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

LINK: https://www.interviewbit.com/problems/ways-to-decode/
*/

int Solution::numDecodings(string A)
{
    int n = A.length();
 
    long long int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = dp[1] = 1;
    if(A[0]=='0')
        dp[1] = 0;
 
    for(int i=2;i<=n;i++)
    {
        if(A[i-1]!='0')
            dp[i] = dp[i-1];
 
        if(A[i-2]=='0')
            continue;
 
        int val = (A[i-2]-'0')*10 + (A[i-1]-'0');
 
        if(val<=26 && val>0)
            dp[i] += dp[i-2];
        else
        if(A[i-1]=='0')
            dp[i] = 0;
 
    }
    return dp[n];
}