/*
Given a number N, return number of ways you can draw N chords in a circle with 2*N points such that no 2 chords intersect.
Two ways are different if there exists a chord which is present in one way and not in other.

For example,

N=2
If points are numbered 1 to 4 in clockwise direction, then different ways to draw chords are:
{(1-2), (3-4)} and {(1-4), (2-3)}

So, we return 2.
Notes:

1 ≤ N ≤ 1000
Return answer modulo 109+7.

LINK: https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/
*/

#define MOD 1000000007
 
int Solution::chordCnt(int n)
{
    long long int dp[n+1];
 
    dp[0] = dp[1] = 1;
 
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
 
        for(int j=0;j<i;j++)
            dp[i] = (dp[i] + (dp[j]*dp[i-j-1])%MOD)%MOD;
    }
    return dp[n];
}