/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10, 8]
Return : [-1, 4, -1, 2, 2]

Example 2:

Input : A : [3, 2, 1]
Return : [-1, -1, -1]

LINK: https://www.interviewbit.com/problems/nearest-smaller-element/
*/

vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    int n = A.size();
    vector<int> v;
 
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top() >= A[i])
            st.pop();
        if(st.empty())
            v.push_back(-1);
        else
            v.push_back(st.top());
        st.push(A[i]);
    }
    return v;
}