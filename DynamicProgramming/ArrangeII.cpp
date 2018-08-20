/*
You are given a sequence of black and white horses, and a set of K stables numbered 1 to K. You have to accommodate the horses into the stables in such a way that the following conditions are satisfied:

You fill the horses into the stables preserving the relative order of horses. For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1. You have to preserve the ordering of the horses.
No stable should be empty and no horse should be left unaccommodated.
Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements
Example:


Input: {WWWB} , K = 2
Output: 0

Explanation:
We have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
for first choice we will get 1*0 + 2*1 = 2.
for second choice we will get 2*0 + 1*1 = 1.
for third choice we will get 3*0 + 0*1 = 0.

Of the 3 choices, the third choice is the best option. 

If a solution is not possible, then return -1

LINK: https://www.interviewbit.com/problems/arrange-ii/
*/

typedef long long int ll;
 
int Solution::arrange(string A, int B)
{
    int n = A.length();
 
    if(n<B)
        return -1;
 
    int wh = 0, bh = 0;
 
    ll dp[B][n];
 
    for(int i=0;i<n;i++)
    {
        if(A[i]=='B')
            bh++;
        else
            wh++;
        dp[0][i] = bh*wh;
    }
 
    for(int i=1;i<B;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j] = INT_MAX;
 
            if(i>j)
                continue;
 
            bh = wh = 0;
 
            for(int k=j;k>0;k--)
            {
                if(A[k]=='B')
                    bh++;
                else
                    wh++;
                dp[i][j] = min(dp[i][j], dp[i-1][k-1] + (bh*wh));
            }
        }
    }
    return dp[B-1][n-1];
}