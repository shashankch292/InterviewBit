/*
Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors.

Example:

Input : 
Prime numbers : [2,3,5] 
k : 5

If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be: 

Output: 
{2,3,4,5,6}

Explanation : 
4 = p1 * p1 ( 2 * 2 )
6 = p1 * p2 ( 2 * 3 )

Note: The sequence should be sorted in ascending order

LINK: https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
*/

vector<int> Solution::solve(int A, int B, int C, int D)
{
    vector<int> res;
    if(D==0)
        return res;
 
    int ia = 0, ib = 0, ic = 0;
    int nexta = A, nextb = B, nextc = C;
 
    for(int i=0;i<D;i++)
    {
        res.push_back(min(nexta, min(nextb, nextc)));
 
        if(res[i] == nexta)
            nexta = res[ia++] * A;
        if(res[i] == nextb)
            nextb = res[ib++] * B;
        if(res[i] == nextc)
            nextc = res[ic++] * C;
    }
 
    return res;
}
