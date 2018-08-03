/*
Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

For example,

HammingDistance(2, 7) = 2, as only the first and the third bit differs in the binary representation of 2 (010) and 7 (111).

Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.
Return the answer modulo 1000000007.

Example

Let f(x, y) be the hamming distance defined above.

A=[2, 4, 6]

We return,
f(2, 2) + f(2, 4) + f(2, 6) + 
f(4, 2) + f(4, 4) + f(4, 6) +
f(6, 2) + f(6, 4) + f(6, 6) = 

0 + 2 + 1
2 + 0 + 1
1 + 1 + 0 = 8

LINK: https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
*/

#define MOD 1000000007
 
int Solution::hammingDistance(const vector<int> &A)
{
    int n=A.size();
    int bit[32];
    memset(bit,0,sizeof(bit));
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<32;j++)
        {
            if((A[i]>>j)&1)
                bit[j]++;
        }
    }
 
    long long int ans = 0;
 
    for(int i=0;i<31;i++)
    {
        long long int a = bit[i], b = n-bit[i];
        ans += ((a%MOD)*(b%MOD))%MOD;
    }
    ans = (ans*2)%MOD;
    
    return ans;
}