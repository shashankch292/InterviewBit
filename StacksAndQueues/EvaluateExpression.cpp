/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

LINK: https://www.interviewbit.com/problems/evaluate-expression/
*/

int Solution::evalRPN(vector<string> &A)
{
    stack<int> st;
    int n = A.size();
 
    for(int i=0;i<n;i++)
    {
        if(A[i]=="+" || A[i]=="-" || A[i]=="*" || A[i]=="/")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            if(A[i]=="+")
                num1 = num1 + num2;
            else
            if(A[i]=="-")
                num1 = num1 - num2;
            else
            if(A[i]=="*")
                num1 = num1 * num2;
            else
            if(A[i]=="/")
                num1 = num1 / num2;
            st.push(num1);
        }
        else
            st.push(stoi(A[i]));
    }
    return st.top();
}