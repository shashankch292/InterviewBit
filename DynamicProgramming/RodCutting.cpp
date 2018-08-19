/*
There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

Notes:

Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
N can be upto 109.
For example,

N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
___________________|_______________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13


So, we return [2, 1, 5].

LINK: https://www.interviewbit.com/problems/rod-cutting/
*/

typedef long long int ll;
 
vector<int> res, cuts;
vector<vector<ll> > dp;
vector<vector<int> > parent;
 
ll solve(int l, int r)
{
    if((l+1)>=r)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
 
    ll ans = LLONG_MAX;
    int ind = -1;
 
    for(int i=l+1;i<r;i++)
    {
        ll temp = cuts[r] - cuts[l] + solve(l,i) + solve(i,r);
 
        if(ans > temp)
        {
            ans = temp;
            ind = i;
        }
    }
 
    parent[l][r] = ind;
    return dp[l][r] = ans;
}
 
void form(int l, int r)
{
    if((l+1)>=r)
        return;
 
    res.push_back(cuts[parent[l][r]]);
 
    form(l, parent[l][r]);
    form(parent[l][r], r);
}
 
vector<int> Solution::rodCut(int A, vector<int> &B)
{
    if(B.size()==0 || B.size()==1)
        return B;
 
    B.push_back(A);
    B.insert(B.begin(), 0);
 
    dp.clear();
    parent.clear();
    cuts.clear();
    res.clear();
 
    int n = B.size();
    cuts = B;
 
    dp.resize(n, vector<ll>(n, -1));
    parent.resize(n, vector<int>(n));
 
    solve(0,n-1);
 
    form(0,n-1);
 
    return res;
}