/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

LINK: https://www.interviewbit.com/problems/window-string/
*/

string Solution::minWindow(string A, string B)
{
    int n = A.length();
    int hash[256] = {0};
 
    for(int i=0;i<B.length();i++)
        hash[B[i]]--;
 
    int ind = INT_MAX, len = INT_MAX;
 
    int i=0,j=0;
    hash[A[j]]++;
 
    while(i<=j && j<n)
    {
        bool flag = true;
        for(int k=0;k<256;k++)
        {
            if(hash[k]<0)
            {
                flag=false;
                break;
            }
        }
 
        if(flag)
        {
            if(j-i+1 < len)
            {
                len = j-i+1;
                ind = i;
            }
            hash[A[i]]--;
            i++;
        }
        else
        {
            j++;
            hash[A[j]]++;
        }
        if(i>j)
        {
            j++;
            hash[A[j]]++;
        }
    }
 
    if(ind==INT_MAX)
        return "";
    return A.substr(ind,len);
}