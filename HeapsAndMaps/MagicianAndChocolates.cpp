/*
Given N bags, each bag contains Ai chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Ai chocolates, then the magician fills the ith bag with floor(Ai/2) chocolates.

Given Ai for 1 <= i <= N, find the maximum number of chocolates kid can eat in K units of time.

For example,

K = 3
N = 2
A = 6 5

Return: 14
At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates
At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates
At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate
so, total number of chocolates eaten: 6 + 5 + 3 = 14

Note: Return your answer modulo 10^9+7

LINK: https://www.interviewbit.com/problems/magician-and-chocolates/
*/

#define MOD 1000000007
 
int Solution::nchoc(int A, vector<int> &B)
{
    long long int ans = 0;
    int n = B.size();
    priority_queue<int> pq;
 
    for(int i=0;i<n;i++)
        pq.push(B[i]);
 
    for(int i=0;i<A;i++)
    {
        int val = pq.top();
        pq.pop();
        ans = (ans+val)%MOD;
        pq.push(val/2);
    }
    return (int)ans;
}