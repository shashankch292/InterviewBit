/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003

LINK: https://www.interviewbit.com/problems/sorted-permutation-rank/
*/

typedef long long int ll;
#define MOD 1000003
 
ll fact(ll n)
{
    if(n<=1)
        return 1;
    else
        return (n%MOD * fact(n-1)%MOD)%MOD;
}
 
 
int Solution::findRank(string A)
{
    ll n = A.length();
    ll mul = fact(n);
 
    ll rank = 0;
 
    for(int i=0;i<n;i++)
    {
        mul /= (n-i);
 
        ll cnt=0;
 
        for(int j=i+1;j<n;j++)
            if(A[i]>A[j])
                cnt++;
 
        rank +=(cnt*fact(n-i-1))%MOD;
    }
 
    return (rank+1)%MOD;
}