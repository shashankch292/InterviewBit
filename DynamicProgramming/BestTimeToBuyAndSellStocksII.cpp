/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example :

Input : [1 2 3]
Return : 2

LINK: https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/
*/

int Solution::maxProfit(const vector<int> &A)
{
    int n = A.size();
    int res = 0;
 
    int i = 0;
 
    while(i<n-1)
    {
        while(i<n-1 && A[i+1]<=A[i])
            i++;
 
        if(i==n-1)
            break;
 
        int j = i;
 
        while(i<n-1 && A[i+1]>=A[i])
            i++;
 
        res += (A[i] - A[j]);
        i++;
    }
    return res;
}