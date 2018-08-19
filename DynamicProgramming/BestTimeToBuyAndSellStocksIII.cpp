/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 1 2]
Output : 2

Explanation : 
  Day 1 : Buy 
  Day 2 : Sell
  Day 3 : Buy
  Day 4 : Sell

LINK: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/
*/

int Solution::maxProfit(const vector<int> &A)
{
    int n = A.size();
    if(n==0)
        return 0;
    int dp[n];
    memset(dp,0,sizeof(dp));
 
    int max_ele = A[n-1];
 
    for(int i=n-2;i>=0;i--)
    {
        if(A[i] > max_ele)
            max_ele  = A[i];
 
        dp[i] = max(dp[i+1], max_ele - A[i]);
    }
 
    int min_ele = A[0];
 
    for(int i=1;i<n;i++)
    {
        if(A[i] < min_ele)
            min_ele = A[i];
 
        dp[i] = max(dp[i-1], dp[i] + (A[i]-min_ele));
    }
 
    return dp[n-1];
}