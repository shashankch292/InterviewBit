/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)

LINK: https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/
*/

int largestRectangleArea(vector<int> &A)
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
 
int Solution::maximalRectangle(vector<vector<int> > &A)
{
    int m = A.size();
    int n = A[0].size();
 
    int ans = largestRectangleArea(A[0]);
 
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(A[i][j]!=0)
                A[i][j] += A[i-1][j];
 
            ans = max(ans, largestRectangleArea(A[i]));
        }
    }
    return ans;
}