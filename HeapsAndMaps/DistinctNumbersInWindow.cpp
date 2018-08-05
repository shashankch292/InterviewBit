/*
You are given an array of N integers, A1, A2 ,…, AN and an integer K. Return the of count of distinct numbers in all windows of size K.

Formally, return an array of size N-K+1 where i’th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.

Note:

If K > N, return empty array.
For example,

A=[1, 2, 1, 3, 4, 3] and K = 3

All windows of size K are

[1, 2, 1]
[2, 1, 3]
[1, 3, 4]
[3, 4, 3]

So, we return an array [2, 3, 3, 2].

LINK: https://www.interviewbit.com/problems/distinct-numbers-in-window/
*/

vector<int> Solution::dNums(vector<int> &A, int B)
{
    vector<int> res;
 
    int n = A.size();
    if(B>n)
        return res;
 
    unordered_map<int, int> mp;
 
    for(int i=0;i<B;i++)
        mp[A[i]]++;
    
    int cnt = mp.size();
    res.push_back(cnt);
 
    for(int i=B;i<n;i++)
    {
        if(mp[A[i-B]]==1)
            cnt--;
        mp[A[i-B]]--;
        if(mp[A[i]]==0)
            cnt++;
        mp[A[i]]++;
        res.push_back(cnt);
    }
    return res;
}
