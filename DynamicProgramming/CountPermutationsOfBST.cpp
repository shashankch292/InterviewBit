/*
You are given two positive integers A and B. For all permutations of [1, 2, …, A], we create a BST. Count how many of these have height B.

Notes:

Values of a permutation are sequentially inserted into the BST by general rules i.e in increasing order of indices.
Height of BST is maximum number of edges between root and a leaf.
Return answer modulo 109 + 7.
Expected time complexity is worst case O(N4).
1 ≤ N ≤ 50
For example,

A = 3, B = 1

Two permutations [2, 1, 3] and [2, 3, 1] generate a BST of height 1.
In both cases the BST formed is

    2
   / \
  1   3  


Another example,
A = 3, B = 2
Return 4.

Next question, can you do the problem in O(N3)?

LINK: https://www.interviewbit.com/problems/count-permutations-of-bst/
*/

typedef long long int ll;
#define MOD 1000000007
 
long long int comb[55][55];
 
void comb_ini()
{
    int i,j;
    comb[0][0]=1;
    for(i=1;i<55;i++)
    {
        comb[i][0]=1;
        for(j=1;j<=i;j++)
        {
            comb[i][j]=(comb[i-1][j]%MOD+comb[i-1][j-1]%MOD)%MOD;
        }
    }
}
 
int Solution::cntPermBST(int A, int B)
{
    comb_ini();
 
    if(A==0)
        return 0;
 
    B++;
 
    ll dp[A+1][B+1];
 
    memset(dp,0,sizeof(dp));
 
    dp[0][0] = 1;
    dp[1][1] = 1;
 
    for(int i=2;i<=A;i++)
    {
        for(int j=2;j<=B;j++)
        {
            ll ans = 0;
 
            for(int k=0;k<i;k++)
            {
                int l = k;
                int r = i-k-1;
 
                ll val = 0;
 
                for(int p=0;p<j-1;p++)
                    val = (val + (dp[r][p] * dp[l][j-1])%MOD)%MOD;
 
                for(int p=0;p<j-1;p++)
                    val = (val + (dp[l][p] * dp[r][j-1])%MOD)%MOD;
 
                val = (val + (dp[l][j-1] * dp[r][j-1])%MOD)%MOD;
 
                ans = (ans + (val * comb[i-1][l]))%MOD;
            }
 
            dp[i][j] = ans;
        }
    }
 
    return dp[A][B];
}