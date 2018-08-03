/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Rain water trapped: Example 1

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

LINK: https://www.interviewbit.com/problems/rain-water-trapped/
*/

int Solution::trap(const vector<int> &A)
{
    int n = A.size();
 
    int l = 0, r = n-1;
    int lmx = 0, rmx = 0, ans = 0;
 
    while(l<=r)
    {
        if(A[l]<A[r])
        {
            if(A[l] > lmx)
                lmx = A[l];
            else
                ans += lmx - A[l];
            l++;
        }
        else
        {
            if(A[r] > rmx)
                rmx = A[r];
            else
                ans += rmx - A[r];
            r--;
        }
    }
    return ans;
}