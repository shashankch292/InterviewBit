/*
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9

LINK: https://www.interviewbit.com/problems/maxspprod/
*/

int Solution::maxSpecialProduct(vector<int> &A)
{
    int n=A.size();
    stack<pair<int,int>> st;
 
    long long int larr[n],rarr[n];
 
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top().first <= A[i])
            st.pop();
        
        if(st.empty())
            larr[i]=0;
        else
            larr[i]=st.top().second;
        st.push({A[i],i});
    }
 
    while(!st.empty())
        st.pop();
 
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top().first <= A[i])
            st.pop();
        
        if(st.empty())
            rarr[i]=0;
        else
            rarr[i]=st.top().second;
        st.push({A[i],i});
    }
 
    long long int ans = -1;
 
    for(int i=0;i<n;i++)
    {
        ans = max(ans, larr[i]*rarr[i]);
    }
 
    return ans%1000000007;
}