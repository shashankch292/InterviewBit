/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example :

Input : [1 2]
Return :  1

LINK: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/
*/

int Solution::maxProfit(const vector<int> &A)
{
    int res = 0;
    int n = A.size();
    if(n==0)
        return res;
 
    int min_ele = A[0];
 
    for(int i=1;i<n;i++)
    {
        if(min_ele > A[i])
            min_ele = A[i];
 
        res = max(res, A[i] - min_ele);
    }
    return res;
}