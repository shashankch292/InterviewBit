/*
Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES
Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

LINK: https://www.interviewbit.com/problems/redundant-braces/
*/

int Solution::braces(string s)
{
    stack<char> st;
    int n = s.length();
 
    for(int i=0;i<n;i++)
    {
        if(s[i]==')')
        {
            char top = st.top();
            st.pop();
            bool flag=true;
 
            while(top!='(')
            {
                if(top=='+' || top=='-' || top=='*' || top=='/')
                    flag = false;
                top = st.top();
                st.pop();
            }
            if(flag)
                return 1;
        }
        else
            st.push(s[i]);
    }
    return 0;
}