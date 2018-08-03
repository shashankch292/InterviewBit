/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)

LINK: https://www.interviewbit.com/problems/max-distance/
*/

int Solution::maximumGap(const vector<int> &A) 
{
    int n = A.size();
    vector<pair<int,int>> v(n);
 
    for(int i=0;i<n;i++)
    {
        v[i] = {A[i],i+1};
    }
 
    sort(v.begin(),v.end());
 
    int mx[n], mn[n];
    mn[0] = v[0].second;
    mx[n-1] = v[n-1].second;
 
    for(int i=1;i<n;i++)
        mn[i] = min(mn[i-1],v[i].second);
 
    for(int i=n-2;i>=0;i--)
        mx[i] = max(mx[i+1],v[i].second);
 
    int ans=-1;
 
    for(int i=0;i<n;i++)
        ans = max(ans, mx[i]-mn[i]);
 
    return ans;
}