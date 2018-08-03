/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.

LINK: https://www.interviewbit.com/problems/maximum-consecutive-gap/
*/

struct bckt
{
    int mn,mx;    
};
 
int Solution::maximumGap(const vector<int> &A)
{
    int n=A.size();
    if(n<2)
        return 0;
 
    bckt bucket[n];
 
    int k,mn = INT_MAX, mx = INT_MIN;
 
    for(int i=0;i<n;i++)
    {
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
        bucket[i].mn = INT_MAX;
        bucket[i].mx = INT_MIN;
    }
 
    if(n==2)
        return mx-mn;
 
    float interval = ((float)(mx-mn))/((float)n);
 
    for(int i=0;i<n;i++)
    {
        if(A[i]==mx || A[i]==mn)
            continue;
 
        k = ((A[i]-mn)/interval);
 
        bucket[k].mx = max(bucket[k].mx, A[i]);
        bucket[k].mn = min(bucket[k].mn, A[i]);
    }
 
    int prev = mn, maxgp = 0;
 
    for(int i=0;i<n;i++)
    {
        if(bucket[i].mn == INT_MAX)
            continue;
 
        maxgp = max(maxgp, bucket[i].mn-prev);
        prev = bucket[i].mx;
    }
 
    maxgp = max(maxgp, mx-prev);
 
    return maxgp;
}