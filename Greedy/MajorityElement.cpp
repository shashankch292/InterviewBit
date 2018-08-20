/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2. 

LINK: https://www.interviewbit.com/problems/majority-element/
*/

int Solution::majorityElement(const vector<int> &A)
{
    int n = A.size();
    int cnt = 1;
    int majInd = 0;
 
    for(int i=1;i<n;i++)
    {
        if(A[majInd]==A[i])
            cnt++;
        else
            cnt--;
 
        if(cnt==0)
        {
            cnt = 1;
            majInd = i;
        }
    }
 
    return A[majInd];
}