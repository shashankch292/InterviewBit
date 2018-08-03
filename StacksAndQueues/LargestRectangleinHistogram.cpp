/*
Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

LINK: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
*/

int Solution::largestRectangleArea(vector<int> &A)
{
    int n = A.size();
    int mxarea = 0, i = 0;
 
    stack<int> st;
 
    while(i<n)
    {
        if(st.empty() || A[st.top()] <= A[i])
            st.push(i++);
        else
        {
            int ind = st.top();
            st.pop();
 
            int area = A[ind] * (st.empty() ? i : i - st.top() - 1);
 
            mxarea = max(mxarea, area);
        }
    }
 
    while(!st.empty())
    {
        int ind = st.top();
        st.pop();
 
        int area = A[ind] * (st.empty() ? i : i - st.top() - 1);
 
        mxarea = max(mxarea, area);
    }
    return mxarea;
}