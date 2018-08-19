/*
Given A, how many structurally unique BST’s (binary search trees) that store values 1...A?

Example :

Given A = 3, there are a total of 5 unique BST’s.


   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

LINK: https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
*/

vector<int> dp;
 
int solve(int n)
{
    if(dp[n]!=-1)
        return dp[n];
 
    int ans = 0;
 
    for(int k=0;k<n;k++)
        ans += (solve(k)*solve(n-k-1));
 
    return dp[n] = ans;
}
 
int Solution::numTrees(int A)
{
    if(A==0 || A==1)
        return A;
 
    dp.clear();
    dp.resize(A+1,-1);
    dp[0] = dp[1] = 1;
 
    solve(A);
 
    return dp[A];
}