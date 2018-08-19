/*
Given a 3Xn board, find the number of ways to color it using at most 4 colors such that no two adjacent boxes have same color. Diagonal neighbors are not treated as adjacent boxes. 
Output the ways%1000000007 as the answer grows quickly.

1<= n < 100000

Example:
Input: n = 1
Output: 36

LINK: https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
*/

typedef long long int ll;
#define MOD 1000000007
 
int Solution::solve(int A)
{
    ll c2 = 12;
    ll c3 = 24;
 
    while(A>1)
    {
        ll temp = c3;
        c3 = (11*c3 + 10*c2)%MOD;
        c2 = (5*temp + 7*c2)%MOD;
        A--;
    }
 
    return (c2 + c3)%MOD;
}