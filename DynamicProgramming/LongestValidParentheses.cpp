/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

LINK: https://www.interviewbit.com/problems/longest-valid-parentheses/
*/

int Solution::longestValidParentheses(string A)
{
    int n = A.length();
 
    stack<int> st;
    st.push(-1);
 
    int res = 0;
 
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
            st.push(i);
        else
        {
            st.pop();
 
            if(!st.empty())
                res = max(res, i-st.top());
            else
                st.push(i);
        }
    }
    return res;
}