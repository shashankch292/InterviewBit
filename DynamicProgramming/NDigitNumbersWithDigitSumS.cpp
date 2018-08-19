/*
Find out the number of N digit numbers, whose digits on being added equals to a given number S. Note that a valid number starts from digits 1-9 except the number 0 itself. i.e. leading zeroes are not allowed.

Since the answer can be large, output answer modulo 1000000007

**

N = 2, S = 4 
Valid numbers are {22, 31, 13, 40} 
Hence output 4.

LINK: https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
*/

typedef long long int ll;
#define MOD 1000000007
 
vector<vector<int> > dp;
 
int count(int n, int s)
{
    if(n==0)
        return s==0;
 
    if(dp[n][s]!=-1)
        return dp[n][s];
 
    ll ans = 0;
 
    for(int i=0;i<10;i++)
        if(s-i>=0)
            ans = (ans + count(n-1,s-i))%MOD;
 
    return dp[n][s] = ans;
}
 
int Solution::solve(int A, int B)
{
    if(A==0)
        return 0;
    if(A==1 && B==0)
        return 1;
 
    dp.clear();
    dp.resize(A,vector<int>(B,-1));
 
    ll ans = 0;
 
    for(int i=1;i<10;i++)
        if(B-i>=0)
            ans = (ans + count(A-1,B-i))%MOD;
 
    return ans;
}